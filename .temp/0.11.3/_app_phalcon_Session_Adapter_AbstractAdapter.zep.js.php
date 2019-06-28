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
    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Session\\Adapter',
    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Storage\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
        'line' => 13,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
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
        'name' => 'SessionHandlerInterface',
        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
        'line' => 14,
        'char' => 28,
      ),
    ),
    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
    'line' => 16,
    'char' => 8,
  ),
  4 => 
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
        'value' => 'SessionHandlerInterface',
        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
        'line' => 17,
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
     * @var <AdapterInterface>
     *',
          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
          'line' => 25,
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
          'name' => 'close',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 28,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 29,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Close
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
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 27,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
            'line' => 27,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
          'line' => 26,
          'last-line' => 33,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'destroy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 34,
              'char' => 35,
            ),
          ),
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                        'line' => 36,
                        'char' => 21,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 36,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 36,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                  'line' => 36,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 36,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapter',
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 36,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 36,
                    'char' => 40,
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
                        'value' => 'id',
                        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                        'line' => 36,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 36,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                  'line' => 36,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 36,
                'char' => 49,
              ),
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
                        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                        'line' => 37,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'adapter',
                        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                        'line' => 37,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 37,
                      'char' => 34,
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
                          'value' => 'id',
                          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                          'line' => 37,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                        'line' => 37,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 37,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                  'line' => 38,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 40,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 40,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 41,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Destroy
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
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 35,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
            'line' => 35,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
          'line' => 34,
          'last-line' => 45,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'gc',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'maxlifetime',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 46,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 48,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 49,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Garbage Collector
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
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 47,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
            'line' => 47,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
          'line' => 46,
          'last-line' => 53,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'read',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 54,
              'char' => 32,
            ),
          ),
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
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 56,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 56,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                  'line' => 56,
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
                      'value' => 'id',
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 56,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 56,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 56,
                'char' => 38,
              ),
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 55,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
            'line' => 55,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
          'line' => 54,
          'last-line' => 61,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'open',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'savePath',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 62,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'sessionName',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 62,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 64,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 65,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Open
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
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
          'line' => 62,
          'last-line' => 69,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'write',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 70,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 70,
              'char' => 43,
            ),
          ),
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
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 72,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 72,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                  'line' => 72,
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
                      'value' => 'id',
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 72,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 72,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                      'line' => 72,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                    'line' => 72,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 72,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Write
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
                'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
                'line' => 71,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
          'line' => 70,
          'last-line' => 74,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
      'line' => 16,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Session/Adapter/AbstractAdapter.zep',
    'line' => 16,
    'char' => 14,
  ),
);