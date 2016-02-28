TEMPLATE = subdirs

app.depends = core
test.depends = core

SUBDIRS += \
    app \
    core \
    test
