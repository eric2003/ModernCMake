cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

include(ExternalProject)

ExternalProject_Add(foobar
  GIT_REPOSITORY    git@github.com:eric2003/Foo.git
  GIT_TAG           0.0.1
)
