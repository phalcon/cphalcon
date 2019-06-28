<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Annotations/Reflection.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations',
    'file' => '/app/phalcon/Annotations/Reflection.zep',
    'line' => 13,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Annotations\\Collection',
        'file' => '/app/phalcon/Annotations/Reflection.zep',
        'line' => 13,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Reflection.zep',
    'line' => 32,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *```php
 * use Phalcon\\Annotations\\Reader;
 * use Phalcon\\Annotations\\Reflection;
 *
 * // Parse the annotations in a class
 * $reader = new Reader();
 * $parsing = $reader->parse("MyComponent");
 *
 * // Create the reflection
 * $reflection = new Reflection($parsing);
 *
 * // Get the annotations in the class docblock
 * $classAnnotations = $reflection->getClassAnnotations();
 *```
 *',
    'file' => '/app/phalcon/Annotations/Reflection.zep',
    'line' => 33,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Reflection',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'classAnnotations',
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 37,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'methodAnnotations',
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 39,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'propertyAnnotations',
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 43,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'reflectionData',
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 48,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'reflectionData',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 49,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 49,
              'char' => 58,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'reflectionData',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'reflectionData',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 51,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 51,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 52,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Annotations\\Reflection constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Reflection.zep',
            'line' => 50,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 49,
          'last-line' => 56,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => '__set_state',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 57,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'reflectionData',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 59,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 64,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'reflectionData',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 64,
                  'char' => 55,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 64,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'reflectionData',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 64,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 64,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 64,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'self',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reflectionData',
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 65,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 65,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 65,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 68,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'self',
                'dynamic' => 0,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 68,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 69,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Restores the state of a Phalcon\\Annotations\\Reflection variable export
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Reflection',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 58,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 58,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Reflection.zep',
            'line' => 58,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 57,
          'last-line' => 73,
          'char' => 26,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getClassAnnotations',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'reflectionClass',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 76,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 78,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 78,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'classAnnotations',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 78,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 78,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 78,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 78,
                'char' => 44,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflectionClass',
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 79,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 79,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reflectionData',
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 79,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 79,
                        'char' => 59,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'class',
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 79,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 79,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 79,
                    'char' => 67,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'classAnnotations',
                          'expr' => 
                          array (
                            'type' => 'new',
                            'class' => 'Collection',
                            'dynamic' => 0,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'reflectionClass',
                                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                                  'line' => 80,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Annotations/Reflection.zep',
                                'line' => 80,
                                'char' => 76,
                              ),
                            ),
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 80,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 80,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 81,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'classAnnotations',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 82,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 82,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 83,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 86,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 86,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 86,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 86,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 87,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in the class docblock
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 74,
                  'char' => 59,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 74,
                'char' => 59,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 75,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Reflection.zep',
            'line' => 75,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 74,
          'last-line' => 91,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMethodsAnnotations',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'reflectionMethods',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 94,
                  'char' => 30,
                ),
                1 => 
                array (
                  'variable' => 'methodName',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 94,
                  'char' => 42,
                ),
                2 => 
                array (
                  'variable' => 'reflectionMethod',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 94,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 96,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 96,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'methodAnnotations',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 96,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 96,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 96,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 96,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflectionMethods',
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 97,
                      'char' => 71,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 97,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reflectionData',
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 97,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 97,
                        'char' => 61,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'methods',
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 97,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 97,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 97,
                    'char' => 71,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'count',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reflectionMethods',
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 98,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 98,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 98,
                        'char' => 45,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'methodAnnotations',
                              'expr' => 
                              array (
                                'type' => 'empty-array',
                                'file' => '/app/phalcon/Annotations/Reflection.zep',
                                'line' => 99,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 99,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 101,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'reflectionMethods',
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 101,
                            'char' => 75,
                          ),
                          'key' => 'methodName',
                          'value' => 'reflectionMethod',
                          'reverse' => 0,
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'object-property-array-index',
                                  'operator' => 'assign',
                                  'variable' => 'this',
                                  'property' => 'methodAnnotations',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'methodName',
                                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                                      'line' => 102,
                                      'char' => 63,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'new',
                                    'class' => 'Collection',
                                    'dynamic' => 0,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'reflectionMethod',
                                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                                          'line' => 104,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                                        'line' => 104,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                                    'line' => 104,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                                  'line' => 104,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 105,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 107,
                          'char' => 26,
                        ),
                        2 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 107,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'methodAnnotations',
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 107,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 107,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 108,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 109,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 111,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'methodAnnotations',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 111,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 111,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 112,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 114,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 114,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'methodAnnotations',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 114,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 114,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 115,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in the methods\' docblocks
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 92,
                  'char' => 63,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 92,
                'char' => 63,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 93,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Reflection.zep',
            'line' => 93,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 92,
          'last-line' => 119,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPropertiesAnnotations',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'reflectionProperties',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 122,
                  'char' => 33,
                ),
                1 => 
                array (
                  'variable' => 'property',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 122,
                  'char' => 43,
                ),
                2 => 
                array (
                  'variable' => 'reflectionProperty',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 122,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 124,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 124,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'propertyAnnotations',
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 124,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 124,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 124,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 124,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflectionProperties',
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 125,
                      'char' => 77,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 125,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reflectionData',
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 125,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 125,
                        'char' => 64,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'properties',
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 125,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 125,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                    'line' => 125,
                    'char' => 77,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'count',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'reflectionProperties',
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 126,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 126,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 126,
                        'char' => 48,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'propertyAnnotations',
                              'expr' => 
                              array (
                                'type' => 'empty-array',
                                'file' => '/app/phalcon/Annotations/Reflection.zep',
                                'line' => 127,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 127,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 129,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'reflectionProperties',
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 129,
                            'char' => 78,
                          ),
                          'key' => 'property',
                          'value' => 'reflectionProperty',
                          'reverse' => 0,
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'object-property-array-index',
                                  'operator' => 'assign',
                                  'variable' => 'this',
                                  'property' => 'propertyAnnotations',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'property',
                                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                                      'line' => 130,
                                      'char' => 63,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'new',
                                    'class' => 'Collection',
                                    'dynamic' => 0,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'reflectionProperty',
                                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                                          'line' => 132,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                                        'line' => 132,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Annotations/Reflection.zep',
                                    'line' => 132,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                                  'line' => 132,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 133,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 135,
                          'char' => 26,
                        ),
                        2 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 135,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'propertyAnnotations',
                              'file' => '/app/phalcon/Annotations/Reflection.zep',
                              'line' => 135,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Annotations/Reflection.zep',
                            'line' => 135,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Annotations/Reflection.zep',
                          'line' => 136,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 137,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 139,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'propertyAnnotations',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Annotations/Reflection.zep',
                        'line' => 139,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Annotations/Reflection.zep',
                      'line' => 139,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 140,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 142,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 142,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'propertyAnnotations',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 142,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 142,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in the properties\' docblocks
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 120,
                  'char' => 66,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 120,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 121,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Reflection.zep',
            'line' => 121,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 120,
          'last-line' => 148,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReflectionData',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 151,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'reflectionData',
                  'file' => '/app/phalcon/Annotations/Reflection.zep',
                  'line' => 151,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 151,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Annotations/Reflection.zep',
              'line' => 152,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the raw parsing intermediate definitions used to construct the
     * reflection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Reflection.zep',
                'line' => 150,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Reflection.zep',
            'line' => 150,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Reflection.zep',
          'line' => 149,
          'last-line' => 153,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Reflection.zep',
      'line' => 33,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Annotations/Reflection.zep',
    'line' => 33,
    'char' => 5,
  ),
);