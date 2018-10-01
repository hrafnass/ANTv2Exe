TEMPLATE = subdirs

SUBDIRS += \
    src/PersonalData \
    src/Gui \
    src/FileAccess

CONFIG+= static #added for static linking
