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
    'file' => '/app/phalcon/Cache/Cache.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cache',
    'file' => '/app/phalcon/Cache/Cache.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Cache/Cache.zep',
        'line' => 13,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Cache/Cache.zep',
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
        'name' => 'Phalcon\\Cache\\Exception\\Exception',
        'file' => '/app/phalcon/Cache/Cache.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Cache/Cache.zep',
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
        'name' => 'Phalcon\\Cache\\Exception\\InvalidArgumentException',
        'file' => '/app/phalcon/Cache/Cache.zep',
        'line' => 15,
        'char' => 53,
      ),
    ),
    'file' => '/app/phalcon/Cache/Cache.zep',
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
        'name' => 'Psr\\SimpleCache\\CacheInterface',
        'file' => '/app/phalcon/Cache/Cache.zep',
        'line' => 16,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Cache/Cache.zep',
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
        'name' => 'Traversable',
        'file' => '/app/phalcon/Cache/Cache.zep',
        'line' => 17,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Cache/Cache.zep',
    'line' => 22,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This component offers caching capabilities for your application.
 * Phalcon\\Cache implements PSR-16.
 *',
    'file' => '/app/phalcon/Cache/Cache.zep',
    'line' => 23,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Cache',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'CacheInterface',
        'file' => '/app/phalcon/Cache/Cache.zep',
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
          'name' => 'adapter',
          'docblock' => '**
     * The adapter
     *
     * @var AdapterInterface
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 30,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 36,
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
              'name' => 'adapter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 37,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 37,
              'char' => 59,
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
                  'property' => 'adapter',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 39,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 39,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor.
     *
     * @param AdapterInterface  adapter The cache adapter
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 38,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 37,
          'last-line' => 46,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 49,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 49,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 49,
                  'char' => 30,
                ),
                'name' => 'clear',
                'call-type' => 1,
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 49,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 50,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Wipes clean the entire cache\'s keys.
     *
     * @return bool True on success and false on failure.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 48,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 48,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 47,
          'last-line' => 61,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'delete',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 62,
              'char' => 35,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 64,
                  'char' => 14,
                ),
                'name' => 'checkKey',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 64,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 64,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 64,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 66,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 66,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 66,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 66,
                  'char' => 30,
                ),
                'name' => 'delete',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 66,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 66,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 66,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 67,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Delete an item from the cache by its unique key.
     *
     * @param string $key The unique cache key of the item to delete.
     *
     * @return bool True if the item was successfully removed. False if there was an error.
     *
     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException
     *   MUST be thrown if the $key string is not a legal value.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 62,
          'last-line' => 79,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'deleteMultiple',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'keys',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 80,
              'char' => 44,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 82,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 82,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 84,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 84,
                  'char' => 14,
                ),
                'name' => 'checkKeys',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keys',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 84,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 84,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 84,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 86,
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
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 86,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 86,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 88,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'keys',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 88,
                'char' => 25,
              ),
              'value' => 'key',
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 89,
                          'char' => 22,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'adapter',
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 89,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 89,
                        'char' => 31,
                      ),
                      'name' => 'delete',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 89,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 89,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 89,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 89,
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
                          'variable' => 'result',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 90,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 90,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 91,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 92,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 94,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 94,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Deletes multiple cache items in a single operation.
     *
     * @param iterable $keys A list of string-based keys to be deleted.
     *
     * @return bool True if the items were successfully removed. False if there was an error.
     *
     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException
     *   MUST be thrown if $keys is neither an array nor a Traversable,
     *   or if any of the $keys are not a legal value.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 81,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 80,
          'last-line' => 107,
          'char' => 19,
        ),
        4 => 
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
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 108,
              'char' => 32,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 108,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 108,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 110,
                  'char' => 14,
                ),
                'name' => 'checkKey',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 110,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 110,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 110,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 112,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 112,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 112,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 112,
                  'char' => 30,
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
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 112,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 112,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 112,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 112,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 112,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 113,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Fetches a value from the cache.
     *
     * @param string $key     The unique key of this item in the cache.
     * @param mixed  $default Default value to return if the key does not exist.
     *
     * @return mixed The value of the item from the cache, or $default in case of cache miss.
     *
     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException
     *   MUST be thrown if the $key string is not a legal value.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 108,
          'last-line' => 126,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMultiple',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'keys',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 127,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 127,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 127,
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
                  'variable' => 'element',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 129,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 130,
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
                  'variable' => 'results',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 130,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 132,
              'char' => 12,
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
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 132,
                  'char' => 14,
                ),
                'name' => 'checkKeys',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'keys',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 132,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 132,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 132,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 134,
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
                  'variable' => 'results',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 134,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 134,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 135,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'keys',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 135,
                'char' => 29,
              ),
              'value' => 'element',
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'results',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'element',
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 136,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 136,
                          'char' => 41,
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
                              'value' => 'element',
                              'file' => '/app/phalcon/Cache/Cache.zep',
                              'line' => 136,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 136,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'defaultValue',
                              'file' => '/app/phalcon/Cache/Cache.zep',
                              'line' => 136,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 136,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 136,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 136,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 137,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 139,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'results',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 139,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 140,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Obtains multiple cache items by their unique keys.
     *
     * @param iterable $keys    A list of keys that can obtained in a single operation.
     * @param mixed    $default Default value to return for keys that do not exist.
     *
     * @return iterable A list of key => value pairs. Cache keys that do not exist or are stale will have $default as value.
     *
     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException
     *   MUST be thrown if $keys is neither an array nor a Traversable,
     *   or if any of the $keys are not a legal value.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 128,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 128,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 127,
          'last-line' => 151,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 152,
              'char' => 32,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 154,
                  'char' => 14,
                ),
                'name' => 'checkKey',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 154,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 154,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 154,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 156,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 156,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 156,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 156,
                  'char' => 30,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 156,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 156,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 156,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 157,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Determines whether an item is present in the cache.
     *
     * @param string $key The cache item key.
     *
     * @return bool
     *
     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException
     *   MUST be thrown if the $key string is not a legal value.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 153,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 153,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 152,
          'last-line' => 172,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 173,
              'char' => 32,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 173,
              'char' => 43,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ttl',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 173,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 173,
              'char' => 59,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 175,
                  'char' => 14,
                ),
                'name' => 'checkKey',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 175,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 175,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 175,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 177,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 177,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 177,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 177,
                  'char' => 30,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 177,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 177,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 177,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 177,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ttl',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 177,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 177,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 177,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 178,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Persists data in the cache, uniquely referenced by a key with an optional expiration TTL time.
     *
     * @param string                 $key   The key of the item to store.
     * @param mixed                  $value The value of the item to store. Must be serializable.
     * @param null|int|\\DateInterval $ttl   Optional. The TTL value of this item. If no value is sent and
     *                                      the driver supports TTL then the library may set a default value
     *                                      for it or let the driver take care of that.
     *
     * @return bool True on success and false on failure.
     *
     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException
     *   MUST be thrown if the $key string is not a legal value.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 174,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 174,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 173,
          'last-line' => 193,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setMultiple',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'values',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 194,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'ttl',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 194,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 194,
              'char' => 59,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 196,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 196,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 197,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 197,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 199,
              'char' => 12,
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
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 199,
                  'char' => 14,
                ),
                'name' => 'checkKeys',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'values',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 199,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 199,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 199,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 201,
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
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 201,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 201,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 202,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'values',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 202,
                'char' => 34,
              ),
              'key' => 'key',
              'value' => 'value',
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 203,
                        'char' => 22,
                      ),
                      'name' => 'set',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 203,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 203,
                          'char' => 30,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 203,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 203,
                          'char' => 37,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ttl',
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 203,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 203,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 203,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 203,
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
                          'variable' => 'result',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Cache/Cache.zep',
                            'line' => 204,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 204,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 205,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 206,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 208,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 208,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 209,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Persists a set of key => value pairs in the cache, with an optional TTL.
     *
     * @param iterable               $values A list of key => value pairs for a multiple-set operation.
     * @param null|int|\\DateInterval $ttl    Optional. The TTL value of this item. If no value is sent and
     *                                       the driver supports TTL then the library may set a default value
     *                                       for it or let the driver take care of that.
     *
     * @return bool True on success and false on failure.
     *
     * @throws Phalcon\\Cache\\Exception\\InvalidArgumentException
     *   MUST be thrown if $values is neither an array nor a Traversable,
     *   or if any of the $values are not a legal value.
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
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 195,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 195,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 194,
          'last-line' => 213,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 214,
              'char' => 40,
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
                  'variable' => 'key',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 216,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 216,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 216,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 218,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'preg_match',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '/[^A-Za-z0-9-_]/',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 218,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 218,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 218,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 218,
                    'char' => 44,
                  ),
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 218,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The key contains invalid characters',
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 221,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 221,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 221,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 222,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 223,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the key. If it contains invalid characters an exception is thrown
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 215,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 214,
          'last-line' => 227,
          'char' => 22,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkKeys',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'keys',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 228,
              'char' => 42,
            ),
          ),
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'keys',
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 230,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 230,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 230,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 230,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'instanceof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'keys',
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 230,
                        'char' => 53,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'Traversable',
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 230,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Cache/Cache.zep',
                      'line' => 230,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 230,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 230,
                  'char' => 68,
                ),
                'file' => '/app/phalcon/Cache/Cache.zep',
                'line' => 230,
                'char' => 68,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InvalidArgumentException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The keys need to be an array or instance of Traversable',
                          'file' => '/app/phalcon/Cache/Cache.zep',
                          'line' => 233,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Cache/Cache.zep',
                        'line' => 233,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Cache/Cache.zep',
                    'line' => 233,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Cache/Cache.zep',
                  'line' => 234,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/Cache.zep',
              'line' => 235,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the key. If it contains invalid characters an exception is thrown
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Cache/Cache.zep',
            'line' => 229,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/Cache.zep',
          'line' => 228,
          'last-line' => 236,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Cache/Cache.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Cache/Cache.zep',
    'line' => 23,
    'char' => 5,
  ),
);