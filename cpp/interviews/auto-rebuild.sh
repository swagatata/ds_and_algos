#!/usr/bin/env fish

# Define the directories to watch for changes
set WATCH_DIRS "include" "src" "tests"

# Define the make command to run
# set MAKE_CMD "make"

# # Function to trigger the rebuild
function trigger_rebuild
    echo "Changes detected, rebuilding..."
    eval $MAKE_CMD
end

# Monitor file changes and trigger the rebuild
fswatch -0 -o $WATCH_DIRS | xargs -0 -n1 -I{} fish -c trigger_rebuild