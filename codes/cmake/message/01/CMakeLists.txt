cmake_minimum_required ( VERSION 3.28 )

project ( testprj )

message(CHECK_START "Finding my things")
list(APPEND CMAKE_MESSAGE_INDENT "  ")
unset(missingComponents)

message(CHECK_START "Finding partA")
# ... do check, assume we find A
message(CHECK_PASS "found")

message(CHECK_START "Finding partB")
# ... do check, assume we don't find B
list(APPEND missingComponents B)
message(CHECK_FAIL "not found")

list(POP_BACK CMAKE_MESSAGE_INDENT)
if(missingComponents)
  message(CHECK_FAIL "missing components: ${missingComponents}")
else()
  message(CHECK_PASS "all components found")
endif()
