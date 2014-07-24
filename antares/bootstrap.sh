#!/bin/bash

# Configuration of bootstrap
product_name="freemodbus library"
product_dir="freemodbus"
product_kcnf_name="LIB_FREEMODBUS"
has_kcnf=true

# Source
echo "$product_name bootstrap for Antares"

if [[ -n $ANTARES_INSTALL_DIR ]]; then

        if [[ -a $ANTARES_INSTALL_DIR/src/lib/contrib/$product_dir ]]; then
                echo "Looks like $product_name is linked into Antares environment..."
                echo "Nothing to be done."
                exit
        fi

        echo "Installing $product_name for Antares..."

        echo "Symlinking..."

        ln -sf `pwd`/src/ $ANTARES_INSTALL_DIR/src/lib/contrib/$product_dir
        ln -sf `pwd`/include/ $ANTARES_INSTALL_DIR/include/lib/$product_dir

        echo "Add to Makefile..."
        echo "subdirs-\$(CONFIG_$product_kcnf_name)+=$product_dir" >> $ANTARES_INSTALL_DIR/src/lib/contrib/Makefile

        if $has_kcnf; then
                echo "Add kcnf info..."
                echo "source antares/src/lib/contrib/$product_dir/kcnf" >> $ANTARES_INSTALL_DIR/src/lib/contrib/kcnf
        fi

        echo "Done."
else
        echo "Antares environment is not found!"
        echo "Nothing to be done."
fi
