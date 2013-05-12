###########################################################################
# Dawid Bazan <dawidbazan@gmail.com>
# Dariusz Synowiec <devemouse@gmail.com>
#
# rules.mk
###########################################################################

###########################################################################
# Compiler settings
###########################################################################
# listing generation rules
# -Wa                              # pass to the assembler 
# -adhlns                          # create assembler listing = list_file_name.lst
LSTGEN = -Wa,-adhlns=$(LSTDIR)/$(*F).lst 

# dependency generation rules
# -MD                              # Instead of outputting the result of preprocessing, 
                                   # output a rule suitable for make describing the dependencies 
                                   # of the main source file
# -MP                              # This option instructs CPP to add a phony target for each dependency other
                                   # than the main file, causing e ach to depend on nothing
                                   # These dummy rules work around errors make gives if you 
                                   # remove header file swithout updating the 'Makefile' to match
# -MF file                         # overrides the default dependency output file
DEPGEN = -MD -MP -MF $(*F).tmp

# C/C++ compiler common flags
# -mcpu=cortex-m3                  # CPU name
# -march=armv7-m                   # CPU architecture        
# -mthumb                          # Generate code for the Thumb instruction set.  The default is to use the 32-bit
#                                  # ARM instruction set. This option automatically enables either 16-bit Thumb-
#                                  # 1 or mixed 16/32-bit Thumb-2 instructions based on the '-mcpu=name' and
#                                  # '-march=name' options. This option is not passed to the assembler. If you want
#                                  # to force assembler files to be interpreted as Thumb code ,either add '.thumb'
#                                  # directive to the source or pass the '-mthumb' option directly to the assembler
#                                  # by prefixin gi twit '-Wa'
# -gdwarf-2                        # Debugging format
# -O2                              # Optimalization level
# -fpromote-loop-indices           # Convert loop indices to word-sized quantities
# -Wall -Wextra                    # Turn all optional warnings plus extra optional
#                                  # optional warnings from -Wall and -Wextra below above line
C_COMMONFLAGS = \
                $(LSTGEN) \
                $(DEPGEN) \
                $(patsubst %,-I%,$(SUBDIRS)) \
                -I. \
                -mcpu=cortex-m3 \
                -march=armv7-m \
                -mthumb \
                -gdwarf-2 \
                -O0 \
                -fpromote-loop-indices \
                -Wall \
                -Wextra \
                -Wimplicit \
                -Wcast-align \
                -Wpointer-arith \
                -Wredundant-decls \
                -Wshadow \
                -Wcast-qual \
                -Wcast-align \
                -fno-exceptions 

# C only compiler flags
# -Wnested-externs                 # Warn if an extern declaration is encountered within a function
# -std=gnu99                       # Defined standard: c99 plus GCC extensions
CFLAGS = \
		$(C_COMMONFLAGS) \
		-Wnested-externs \
		-std=gnu99

# C++ only compiler flags
# -fno-rtti -fno-exceptions        # If you will not use virtual functions 
#                                  # those setting flags will optimalize the code
CPPFLAGS = \
           $(C_COMMONFLAGS) \
           -fno-rtti 

# Assembler compliler flags
# -mcpu=cortex-m3 \                # CPU name
# -mthumb                          # Generate code for the Thumb instruction set.  The default is to use the 32-bit
#                                  # ARM instruction set. This option automatically enables either 16-bit Thumb-
#                                  # 1 or mixed 16/32-bit Thumb-2 instructions based on the '-mcpu=name' and
#                                  # '-march=name' options. This option is not passed to the assembler. If you want
#                                  # to force assembler files to be interpreted as Thumb code ,either add '.thumb'
#                                  # directive to the source or pass the '-mthumb' option directly to the assembler
#                                  # by prefixin gi twit '-Wa'
# -Wa, -gdwarf-2 \                 # Debugging format
#                                  # -adhlns -create assembler listing
ASFLAGS = \
          -adhlns=$(LSTDIR)/$(*F).lst \
          -MD -MP $(*F).tmp \
          -mthumb \
          $(patsubst %,-I%,$(SUBDIRS)) -I. \
          -mcpu=cortex-m3 \
          -gdwarf-2 

# Linker flags
# -Wl                              # pass to the linker, -Map -create map file,
# --cref                           # Output a cross reference table,
# --gc-sections                    # Enable garbage collection of unused input sections
# -T$(LINKERSCRIPT)                # Use this linker script
LDFLAGS = -Map=$(OUTDIR)/$(TARGET).map --cref --gc-sections  \
          -T$(LINKERSCRIPT)

