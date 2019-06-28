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
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations\\Adapter',
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Annotations\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
        'line' => 13,
        'char' => 49,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Annotations\\Reader',
        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Annotations\\Exception',
        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
        'line' => 15,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Annotations\\Collection',
        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
        'line' => 16,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Annotations\\Reflection',
        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
        'line' => 17,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Annotations\\ReaderInterface',
        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
        'line' => 18,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 22,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This is the base class for Phalcon\\Annotations adapters
 *',
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 23,
    'char' => 8,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'AbstractAdapter',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'AdapterInterface',
        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
        'line' => 24,
        'char' => 1,
      ),
    ),
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
          'name' => 'annotations',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
            'line' => 28,
            'char' => 31,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 32,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'reader',
          'docblock' => '**
     * @var Reader
     *',
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 37,
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
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 38,
              'char' => 38,
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
                  'variable' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 40,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'parsedAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 40,
                  'char' => 48,
                ),
                2 => 
                array (
                  'variable' => 'realClassName',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 40,
                  'char' => 63,
                ),
                3 => 
                array (
                  'variable' => 'reader',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 40,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 45,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'className',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 45,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 45,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 45,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 45,
                'char' => 39,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'realClassName',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'get_class',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'className',
                              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                              'line' => 46,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                            'line' => 46,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 46,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 46,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 47,
                  'char' => 9,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'realClassName',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'className',
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 48,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 48,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 49,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 51,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 51,
                      'char' => 23,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'annotations',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 51,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 51,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'realClassName',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 51,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 51,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 51,
                'char' => 51,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 52,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotations',
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 52,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 52,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'realClassName',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 52,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 52,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 53,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 58,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'classAnnotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 58,
                      'char' => 37,
                    ),
                    'name' => 'read',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'realClassName',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 58,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 58,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 58,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 58,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 60,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'classAnnotations',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 60,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 60,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 60,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'classAnnotations',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 60,
                    'char' => 60,
                  ),
                  'right' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 60,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 60,
                  'char' => 68,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 60,
                'char' => 68,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'reader',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 64,
                          'char' => 31,
                        ),
                        'name' => 'getReader',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 64,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 64,
                      'char' => 43,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'parsedAnnotations',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reader',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 65,
                          'char' => 44,
                        ),
                        'name' => 'parse',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'realClassName',
                              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                              'line' => 65,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                            'line' => 65,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 65,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 65,
                      'char' => 65,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 67,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'classAnnotations',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Reflection',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parsedAnnotations',
                              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                              'line' => 67,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                            'line' => 67,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 67,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 67,
                      'char' => 69,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'annotations',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'realClassName',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 68,
                          'char' => 48,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'classAnnotations',
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 68,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 68,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 69,
                  'char' => 20,
                ),
                2 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 69,
                      'char' => 22,
                    ),
                    'name' => 'write',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'realClassName',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 69,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 69,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'classAnnotations',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 69,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 69,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 69,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 70,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 72,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'classAnnotations',
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 72,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Parses or retrieves all the annotations found in a class
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
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 39,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 39,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
            'line' => 39,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 38,
          'last-line' => 77,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 78,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'methodName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 78,
              'char' => 66,
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
                  'variable' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 80,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'methods',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 80,
                  'char' => 38,
                ),
                2 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 80,
                  'char' => 46,
                ),
                3 => 
                array (
                  'variable' => 'methodKey',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 80,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 85,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'classAnnotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 85,
                      'char' => 37,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 85,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 85,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 85,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 85,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 87,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'methods',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'classAnnotations',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 87,
                      'char' => 40,
                    ),
                    'name' => 'getMethodsAnnotations',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 87,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 87,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 89,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'methods',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 89,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 89,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 89,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 89,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'methods',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 90,
                    'char' => 46,
                  ),
                  'key' => 'methodKey',
                  'value' => 'method',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strcasecmp',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'methodKey',
                                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                                'line' => 91,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                              'line' => 91,
                              'char' => 41,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'methodName',
                                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                                'line' => 91,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                              'line' => 91,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 91,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 91,
                        'char' => 55,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'method',
                            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                            'line' => 92,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 93,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 94,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 95,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 100,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Collection',
                'dynamic' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 100,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 101,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in a specific method
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
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 79,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 79,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 78,
          'last-line' => 105,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMethods',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 106,
              'char' => 48,
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
                  'variable' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 108,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 113,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'classAnnotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 113,
                      'char' => 37,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 113,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 113,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 113,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 113,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 115,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 115,
                  'char' => 33,
                ),
                'name' => 'getMethodsAnnotations',
                'call-type' => 1,
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 115,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 116,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in all the class\' methods
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
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 107,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
            'line' => 107,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 106,
          'last-line' => 120,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getProperty',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 121,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'propertyName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 121,
              'char' => 70,
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
                  'variable' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 123,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'properties',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 123,
                  'char' => 41,
                ),
                2 => 
                array (
                  'variable' => 'property',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 123,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 128,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'classAnnotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 128,
                      'char' => 37,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 128,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 128,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 128,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 128,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 130,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'properties',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'classAnnotations',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 130,
                      'char' => 43,
                    ),
                    'name' => 'getPropertiesAnnotations',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 130,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 130,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 132,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'property',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 132,
                    'char' => 54,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'properties',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 132,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'propertyName',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 132,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 132,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 132,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 132,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 136,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 137,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 139,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'property',
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 139,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 140,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in a specific property
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
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 122,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 121,
          'last-line' => 144,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getProperties',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 145,
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
                  'variable' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 147,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 152,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'classAnnotations',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 152,
                      'char' => 37,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                          'line' => 152,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 152,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 152,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 152,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 154,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'classAnnotations',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 154,
                  'char' => 33,
                ),
                'name' => 'getPropertiesAnnotations',
                'call-type' => 1,
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 154,
                'char' => 60,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 155,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotations found in all the class\' methods
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
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 146,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
            'line' => 146,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 145,
          'last-line' => 159,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReader',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 162,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reader',
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 162,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 162,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 162,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 162,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 162,
                'char' => 42,
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
                      'property' => 'reader',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Reader',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                        'line' => 163,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                      'line' => 163,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 164,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 166,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 166,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'reader',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 166,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 166,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 167,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the annotation reader
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
                  'value' => 'ReaderInterface',
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 161,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 161,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
            'line' => 161,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 160,
          'last-line' => 171,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setReader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'reader',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ReaderInterface',
                'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                'line' => 172,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 172,
              'char' => 55,
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
                  'property' => 'reader',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'reader',
                    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                    'line' => 174,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
                  'line' => 174,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the annotations parser
     *',
          'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
          'line' => 172,
          'last-line' => 176,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
      'line' => 23,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Annotations/Adapter/AbstractAdapter.zep',
    'line' => 23,
    'char' => 14,
  ),
);