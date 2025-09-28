#pragma once

// Make manager singleton
#define DECLARE_SINGLE(classname)                                                \
private:                                                                         \
    classname() = default;                                                       \
    friend class SingletonBehaviour<classname>;                               
