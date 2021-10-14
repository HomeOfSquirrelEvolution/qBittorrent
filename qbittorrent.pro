TEMPLATE = subdirs

SUBDIRS += src

OUTPUT += Console

include(version.pri)

# For Qt Creator beautifier
DISTFILES += \
    uncrustify.cfg
