HARNESS_ENTRY = harness
HARNESS_FILE = tdh_mng_create_harness

# This should be a unique identifier for this proof, and will appear on the
# Litani dashboard. It can be human-readable and contain spaces if you wish.
PROOF_UID = tdh_mng_create

DEFINES +=
INCLUDES += -I$(PROOFDIR)
INCLUDES += -I$(SRCDIR)/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/include
INCLUDES += -I$(SRCDIR)/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common
# INCLUDES += -I$(SRCDIR)/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src
# INCLUDES += -I$(SRCDIR)/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/common/crypto
# INCLUDES += -I$(SRCDIR)/verification/formal/tdx/tdx-module-v1.0.01.01/src/common/x86_defs/*
# INCLUDES += -I$(SRCDIR)/verification/formal/tdx/tdx-module-v1.0.01.01/src/common/data_structures

# INCLUDES += -I$(SRCDIR)/verification/formal/tdx/tdx-module-v1.0.01.01/src/common/helpers/*




REMOVE_FUNCTION_BODY +=
UNWINDSET +=

PROOF_SOURCES += $(PROOFDIR)/$(HARNESS_FILE).c
PROJECT_SOURCES += $(SRCDIR)/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/vmm_dispatcher/api_calls/tdh_mng_create.c

# If this proof is found to consume huge amounts of RAM, you can set the
# EXPENSIVE variable. With new enough versions of the proof tools, this will
# restrict the number of EXPENSIVE CBMC jobs running at once. See the
# documentation in Makefile.common under the "Job Pools" heading for details.
# EXPENSIVE = true

# If you require access to a file-local ("static") function or object to conduct
# your proof, set the following (and do not include the original source file
# ("verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/vmm_dispatcher/api_calls/tdh_mng_create.c") in PROJECT_SOURCES).
# REWRITTEN_SOURCES = $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i
# include ../Makefile.common
# $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i_SOURCE = $(SRCDIR)/verification/formal/tdx/Model-Checking-TDX/tdx-module-v1.0.01.01/src/vmm_dispatcher/api_calls/tdh_mng_create.c
# $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i_FUNCTIONS = foo bar
# $(PROOFDIR)/<__SOURCE_FILE_BASENAME__>.i_OBJECTS = baz
# Care is required with variables on the left-hand side: REWRITTEN_SOURCES must
# be set before including Makefile.common, but any use of variables on the
# left-hand side requires those variables to be defined. Hence, _SOURCE,
# _FUNCTIONS, _OBJECTS is set after including Makefile.common.
CHECK_FLAG_MALLOC_MAY_FAIL = 
CHECK_FLAG_MALLOC_FAIL_NULL =
CHECK_FLAG_BOUNDS_CHECK =
CHECK_FLAG_CONVERSION_CHECK =
CHECK_FLAG_DIV_BY_ZERO_CHECK =
CHECK_FLAG_FLOAT_OVERFLOW_CHECK =
CHECK_FLAG_NAN_CHECK =
CHECK_FLAG_POINTER_CHECK =
CHECK_FLAG_POINTER_OVERFLOW_CHECK =
CHECK_FLAG_POINTER_PRIMITIVE_CHECK =
CHECK_FLAG_SIGNED_OVERFLOW_CHECK =
CHECK_FLAG_UNDEFINED_SHIFT_CHECK =
CHECK_FLAG_UNSIGNED_OVERFLOW_CHECK =
CHECK_FLAG_UNWINDING_ASSERTIONS =
CHECK_DEFAULT_UNWIND =
CHECK_FLAG_FLUSH =

include ../Makefile.common
