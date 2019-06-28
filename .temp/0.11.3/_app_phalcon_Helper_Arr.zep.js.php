<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Helper/Arr.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Helper',
    'file' => '/app/phalcon/Helper/Arr.zep',
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
        'name' => 'Phalcon\\Helper\\Exception',
        'file' => '/app/phalcon/Helper/Arr.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Helper/Arr.zep',
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
        'name' => 'stdClass',
        'file' => '/app/phalcon/Helper/Arr.zep',
        'line' => 14,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Helper/Arr.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class offers quick array functions throughout the framework
 *',
    'file' => '/app/phalcon/Helper/Arr.zep',
    'line' => 19,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Arr',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'arrayToObject',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 21,
              'char' => 65,
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
                  'variable' => 'returnObject',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 23,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 23,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 23,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 25,
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
                  'variable' => 'returnObject',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'stdClass',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 25,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 25,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 27,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 27,
                'char' => 38,
              ),
              'key' => 'key',
              'value' => 'value',
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
                      'assign-type' => 'variable-dynamic-object-property',
                      'operator' => 'assign',
                      'variable' => 'returnObject',
                      'property' => 'key',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 28,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 28,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 29,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 31,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'returnObject',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 31,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 32,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 21,
          'last-line' => 42,
          'char' => 32,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'chunk',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 43,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'size',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 43,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'preserveKeys',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 43,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 43,
              'char' => 94,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_chunk',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 45,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 45,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'size',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 45,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 45,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'preserveKeys',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 45,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 45,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 45,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 46,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Chunks an array into smaller arrays of a specified size.
     *
     * @param array $collection
     * @param int   $size
     * @param bool  $preserveKeys
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 44,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 43,
          'last-line' => 56,
          'char' => 32,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'first',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 57,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 57,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 57,
              'char' => 76,
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
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 59,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 61,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'filterCollection',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 61,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 61,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 61,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 61,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 61,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 61,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 63,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'reset',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filtered',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 63,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 63,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 63,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the first element of the collection. If a callable is passed, the
     * element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 58,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 58,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 57,
          'last-line' => 74,
          'char' => 32,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'firstKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 75,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 75,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 75,
              'char' => 79,
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
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 77,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 79,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'filterCollection',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 79,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 79,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 79,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 79,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 79,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 79,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 81,
              'char' => 13,
            ),
            2 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'reset',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filtered',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 81,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 81,
                    'char' => 23,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 81,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 83,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'key',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filtered',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 83,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 83,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 83,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the key of the first element of the collection. If a callable
     * is passed, the element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 76,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 76,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 75,
          'last-line' => 93,
          'char' => 32,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'flatten',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 94,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'deep',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 94,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 94,
              'char' => 78,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 96,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'item',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 96,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 98,
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
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 98,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 98,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 100,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 100,
                'char' => 32,
              ),
              'value' => 'item',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'item',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 101,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 101,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 101,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 101,
                    'char' => 38,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'data',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'item',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 102,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 102,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 103,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'deep',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 104,
                        'char' => 25,
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
                              'variable' => 'data',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'array_merge',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'data',
                                      'file' => '/app/phalcon/Helper/Arr.zep',
                                      'line' => 106,
                                      'char' => 29,
                                    ),
                                    'file' => '/app/phalcon/Helper/Arr.zep',
                                    'line' => 106,
                                    'char' => 29,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'scall',
                                      'dynamic-class' => 0,
                                      'class' => 'self',
                                      'dynamic' => 0,
                                      'name' => 'flatten',
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'item',
                                            'file' => '/app/phalcon/Helper/Arr.zep',
                                            'line' => 107,
                                            'char' => 43,
                                          ),
                                          'file' => '/app/phalcon/Helper/Arr.zep',
                                          'line' => 107,
                                          'char' => 43,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'bool',
                                            'value' => 'true',
                                            'file' => '/app/phalcon/Helper/Arr.zep',
                                            'line' => 107,
                                            'char' => 49,
                                          ),
                                          'file' => '/app/phalcon/Helper/Arr.zep',
                                          'line' => 107,
                                          'char' => 49,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Helper/Arr.zep',
                                      'line' => 108,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Helper/Arr.zep',
                                    'line' => 108,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 108,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 108,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 109,
                          'char' => 17,
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
                              'variable' => 'data',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'array_merge',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'data',
                                      'file' => '/app/phalcon/Helper/Arr.zep',
                                      'line' => 111,
                                      'char' => 29,
                                    ),
                                    'file' => '/app/phalcon/Helper/Arr.zep',
                                    'line' => 111,
                                    'char' => 29,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'array_values',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'item',
                                            'file' => '/app/phalcon/Helper/Arr.zep',
                                            'line' => 112,
                                            'char' => 42,
                                          ),
                                          'file' => '/app/phalcon/Helper/Arr.zep',
                                          'line' => 112,
                                          'char' => 42,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Helper/Arr.zep',
                                      'line' => 113,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Helper/Arr.zep',
                                    'line' => 113,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 113,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 113,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 114,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 115,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 116,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 118,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 118,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 119,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Flattens an array up to the one level depth, unless `$deep` is set to `true`
     *
     * @param array $collection
     * @param bool  $deep
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 95,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 94,
          'last-line' => 123,
          'char' => 32,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 124,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 124,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 124,
                'char' => 91,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 124,
              'char' => 91,
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 126,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 128,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 128,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collection',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 128,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'index',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 128,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 128,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 128,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 128,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 128,
                'char' => 53,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 129,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 130,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 132,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 132,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 133,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Helper method to get an array element or a default
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 125,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 125,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 124,
          'last-line' => 142,
          'char' => 32,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'group',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 143,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 143,
              'char' => 69,
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
                  'variable' => 'element',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 145,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 145,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 146,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 146,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 148,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 148,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 148,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 150,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 150,
                'char' => 35,
              ),
              'value' => 'element',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'not-identical',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'method',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 151,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 151,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 151,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 151,
                          'char' => 43,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'is_callable',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'method',
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 151,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 151,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 151,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 151,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 151,
                      'char' => 67,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'function_exists',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'method',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 151,
                            'char' => 91,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 151,
                          'char' => 91,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 151,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 151,
                    'char' => 93,
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
                          'variable' => 'key',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'call_user_func',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'method',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 152,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 152,
                                'char' => 60,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'element',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 152,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 152,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 152,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 152,
                          'char' => 70,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'array-index-append',
                          'operator' => 'assign',
                          'variable' => 'filtered',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 153,
                              'char' => 33,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'element',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 153,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 153,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 154,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'element',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 154,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 154,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 154,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 154,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'key',
                              'expr' => 
                              array (
                                'type' => 'property-dynamic-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'element',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 155,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'method',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 155,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 155,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 155,
                              'char' => 56,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index-append',
                              'operator' => 'assign',
                              'variable' => 'filtered',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 156,
                                  'char' => 33,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'element',
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 156,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 156,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 157,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 157,
                      'char' => 20,
                    ),
                    1 => 
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
                            'type' => 'variable',
                            'value' => 'element',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 157,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'method',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 157,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 157,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 157,
                        'char' => 44,
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
                              'variable' => 'key',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'element',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 158,
                                  'char' => 46,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'method',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 158,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 158,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 158,
                              'char' => 54,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'array-index-append',
                              'operator' => 'assign',
                              'variable' => 'filtered',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 159,
                                  'char' => 33,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'element',
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 159,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 159,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 160,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 161,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 161,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 163,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'filtered',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 163,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 164,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Groups the elements of an array based on the passed callable
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 144,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 144,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 143,
          'last-line' => 173,
          'char' => 32,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 174,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 174,
              'char' => 66,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 176,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 176,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 176,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 176,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 177,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Helper method to get an array element or a default
     *
     * @param array $collection
     * @param mixed $index
     *
     * return bool
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 175,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 174,
          'last-line' => 186,
          'char' => 32,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'isUnique',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 187,
              'char' => 60,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
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
                        'value' => 'collection',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 189,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 189,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 189,
                  'char' => 36,
                ),
                'right' => 
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
                        'type' => 'fcall',
                        'name' => 'array_unique',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 189,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 189,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 189,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 189,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 189,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 189,
                'char' => 69,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 190,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks a flat list for duplicate values. Returns true if duplicate
     * values exist and false if values are all unique.
     *
     * @param array $collection
     *
     * @return bool
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 188,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 188,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 187,
          'last-line' => 200,
          'char' => 32,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'last',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 201,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 201,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 201,
              'char' => 75,
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
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 203,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 205,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'filterCollection',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 205,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 205,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 205,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 205,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 205,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 205,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 207,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'end',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filtered',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 207,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 207,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 207,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 208,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the last element of the collection. If a callable is passed, the
     * element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 202,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 202,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 201,
          'last-line' => 218,
          'char' => 32,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'lastKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 219,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 219,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 219,
              'char' => 78,
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
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 221,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 223,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'self',
                    'dynamic' => 0,
                    'name' => 'filterCollection',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 223,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 223,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 223,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 223,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 223,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 223,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 225,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'end',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filtered',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 225,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 225,
                    'char' => 21,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 225,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 227,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'key',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filtered',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 227,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 227,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 227,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 228,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the key of the last element of the collection. If a callable is
     * passed, the element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return mixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 220,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 220,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 219,
          'last-line' => 238,
          'char' => 32,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'order',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 239,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 239,
              'char' => 72,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'order',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'asc',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 239,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 239,
              'char' => 92,
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
                  'variable' => 'item',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 241,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 241,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 242,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'sorted',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 242,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 244,
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
                  'variable' => 'sorted',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 244,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 244,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 246,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 246,
                'char' => 32,
              ),
              'value' => 'item',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'item',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 247,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 247,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 247,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 247,
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
                          'variable' => 'key',
                          'expr' => 
                          array (
                            'type' => 'property-dynamic-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'item',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 248,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'attribute',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 248,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 248,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 248,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 249,
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
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'key',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'item',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 250,
                              'char' => 31,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'attribute',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 250,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 250,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 250,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 251,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 253,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'sorted',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 253,
                          'char' => 27,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'item',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 253,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 253,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 254,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 256,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'order',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 256,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'asc',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 256,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 256,
                'char' => 26,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'ksort',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sorted',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 257,
                          'char' => 25,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 257,
                        'char' => 25,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 257,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 258,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'krsort',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sorted',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 259,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 259,
                        'char' => 26,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 259,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 260,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 262,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_values',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sorted',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 262,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 262,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 262,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 263,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sorts a collection of arrays or objects by key
     *
     * @param array  $collection
     * @param mixed  $attr
     * @param string $order
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 240,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 240,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 239,
          'last-line' => 272,
          'char' => 32,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'pluck',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 273,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 273,
              'char' => 73,
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
                  'variable' => 'item',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 275,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 276,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'filtered',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 276,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 278,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 278,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 278,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 280,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 280,
                'char' => 32,
              ),
              'value' => 'item',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'item',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 281,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 281,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 281,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 281,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'property-dynamic-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'item',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 281,
                          'char' => 53,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'element',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 281,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 281,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 281,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 281,
                    'char' => 64,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'filtered',
                          'expr' => 
                          array (
                            'type' => 'property-dynamic-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'item',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 282,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'element',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 282,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 282,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 282,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 283,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'item',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 283,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 283,
                            'char' => 36,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 283,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 283,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'item',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 283,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'element',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 283,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 283,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 283,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 283,
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
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'filtered',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'item',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 284,
                                  'char' => 38,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'element',
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 284,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 284,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 284,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 285,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 286,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 286,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 288,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'filtered',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 288,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 289,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves all of the values for a given key:
     *
     * @param array  $collection
     * @param string $element
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 274,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 274,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 273,
          'last-line' => 299,
          'char' => 32,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 300,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 300,
              'char' => 66,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 300,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 300,
              'char' => 84,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 302,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'index',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 302,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 302,
                'char' => 27,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 303,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 303,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 304,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'collection',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 305,
                          'char' => 33,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 305,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 305,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 306,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 308,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 308,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 309,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Helper method to set an array element
     *
     * @param array $collection
     * @param mixed $value
     * @param mixed $index
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 301,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 301,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 300,
          'last-line' => 318,
          'char' => 32,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'sliceLeft',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 319,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'elements',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 319,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 319,
              'char' => 79,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_slice',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 321,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 321,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 321,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 321,
                    'char' => 41,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'elements',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 321,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 321,
                    'char' => 51,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 321,
                'char' => 52,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 322,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a new array with n elements removed from the right.
     *
     * @param array $collection
     * @param int   $elements
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 320,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 320,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 319,
          'last-line' => 331,
          'char' => 32,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'sliceRight',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 332,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'elements',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 332,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 332,
              'char' => 80,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_slice',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 334,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 334,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'elements',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 334,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 334,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 334,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 335,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a new array with the X elements from the right
     *
     * @param array $collection
     * @param int   $elements
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 333,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 333,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 332,
          'last-line' => 344,
          'char' => 32,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'split',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 345,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'array_keys',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'collection',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 348,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 348,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 348,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 348,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'value' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'array_values',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'collection',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 349,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 349,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 350,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 350,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 350,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 351,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a new array with keys of the passed array as one element and
     * values as another
     *
     * @param array $collection
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 346,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 346,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 345,
          'last-line' => 361,
          'char' => 32,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'validateAll',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 362,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 362,
              'char' => 75,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
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
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'filterCollection',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 364,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 364,
                            'char' => 55,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'method',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 364,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 364,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 364,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 364,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 364,
                  'char' => 68,
                ),
                'right' => 
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
                        'value' => 'collection',
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 364,
                        'char' => 86,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 364,
                      'char' => 86,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 364,
                  'char' => 87,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 364,
                'char' => 87,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 365,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true if the provided function returns true for all elements of
     * the collection, false otherwise.
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return bool
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 363,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 363,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 362,
          'last-line' => 375,
          'char' => 32,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'validateAny',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 376,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 376,
              'char' => 75,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
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
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'self',
                        'dynamic' => 0,
                        'name' => 'filterCollection',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 378,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 378,
                            'char' => 55,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'method',
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 378,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 378,
                            'char' => 63,
                          ),
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 378,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 378,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 378,
                  'char' => 66,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 378,
                  'char' => 69,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 378,
                'char' => 69,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 379,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true if the provided function returns true for at least one
     * element fo the collection, false otherwise.
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return bool
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 377,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 377,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 376,
          'last-line' => 388,
          'char' => 32,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'private',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'filterCollection',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 389,
              'char' => 68,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 389,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 389,
              'char' => 87,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                    'type' => 'null',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 391,
                    'char' => 19,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'method',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 391,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 391,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'is_callable',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 391,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 391,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 391,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 391,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 391,
                'char' => 53,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 392,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 393,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 395,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_filter',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 395,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 395,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'method',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 395,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 395,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 395,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 396,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Helper method to filter the collection
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 390,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 390,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 389,
          'last-line' => 406,
          'char' => 33,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
            2 => 'static',
          ),
          'type' => 'method',
          'name' => 'whiteList',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 407,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'whiteList',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 407,
              'char' => 79,
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
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'whiteList',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_filter',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'whiteList',
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 413,
                          'char' => 22,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 413,
                        'char' => 22,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'closure',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'type' => 'parameter',
                              'name' => 'element',
                              'const' => 0,
                              'data-type' => 'variable',
                              'mandatory' => 0,
                              'reference' => 0,
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 414,
                              'char' => 30,
                            ),
                          ),
                          'right' => 
                          array (
                            0 => 
                            array (
                              'type' => 'return',
                              'expr' => 
                              array (
                                'type' => 'or',
                                'left' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'is_int',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'element',
                                        'file' => '/app/phalcon/Helper/Arr.zep',
                                        'line' => 416,
                                        'char' => 38,
                                      ),
                                      'file' => '/app/phalcon/Helper/Arr.zep',
                                      'line' => 416,
                                      'char' => 38,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 416,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'is_string',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'element',
                                        'file' => '/app/phalcon/Helper/Arr.zep',
                                        'line' => 416,
                                        'char' => 60,
                                      ),
                                      'file' => '/app/phalcon/Helper/Arr.zep',
                                      'line' => 416,
                                      'char' => 60,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Helper/Arr.zep',
                                  'line' => 416,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Helper/Arr.zep',
                                'line' => 416,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Helper/Arr.zep',
                              'line' => 417,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 418,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Helper/Arr.zep',
                        'line' => 418,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 418,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Helper/Arr.zep',
                  'line' => 418,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 420,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_intersect_key',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 421,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 421,
                    'char' => 23,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'array_flip',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'whiteList',
                            'file' => '/app/phalcon/Helper/Arr.zep',
                            'line' => 422,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Helper/Arr.zep',
                          'line' => 422,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Helper/Arr.zep',
                      'line' => 423,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Helper/Arr.zep',
                    'line' => 423,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 423,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Helper/Arr.zep',
              'line' => 424,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * White list filter by key: obtain elements of an array filtering
     * by the keys obtained from the elements of a whitelist
     *
     * @param array $collection
     * @param array $whiteList
     *
     * @return array
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
                'file' => '/app/phalcon/Helper/Arr.zep',
                'line' => 408,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Helper/Arr.zep',
            'line' => 408,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Helper/Arr.zep',
          'line' => 414,
          'last-line' => 425,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Helper/Arr.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Helper/Arr.zep',
    'line' => 19,
    'char' => 5,
  ),
);