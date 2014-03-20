<?php

var_dump(\Phalcon\Annotations\Reader::parseDocBlock('/**
     * Parses a raw doc block returning the annotations found
     *
     * @param string $docBlock
     * @param string|null $file
     * @param int|null $line
     * @return array
     */', null, null));
