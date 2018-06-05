-- define target
target("2017-09-20")

    -- set kind
    set_kind("static")

    -- add files
    add_files("que.cpp")

-- define target
target("1000")

    -- set kind
    set_kind("binary")

    -- add files
    add_files("1000.cpp")

    -- add deps
    add_deps("2017-09-20")

-- define target
target("1002")

    -- set kind
    set_kind("binary")

    -- add files
    add_files("1002.cpp")

    -- add deps
    add_deps("2017-09-20")

