SRC += bakasamppa.c

ifeq ($(strip $(TD_LSFT_CAPSLOCK_ENABLE)), yes)
    OPT_DEFS += -DTD_LSFT_CAPSLOCK_ENABLE
endif