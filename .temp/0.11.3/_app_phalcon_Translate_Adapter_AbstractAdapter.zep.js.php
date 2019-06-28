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
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate\\Adapter',
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Translate\\Exception',
        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Translate\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
        'line' => 15,
        'char' => 47,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Translate\\InterpolatorFactory',
        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
        'line' => 16,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
    'line' => 22,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Translate\\Adapter
 *
 * Base class for Phalcon\\Translate adapters
 *',
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
    'line' => 23,
    'char' => 8,
  ),
  7 => 
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
        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
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
          'name' => 'defaultInterpolator',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 28,
            'char' => 37,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 32,
          'char' => 5,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'interpolatorFactory',
          'docblock' => '**
    * @var InterpolatorFactory
    *',
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 35,
          'char' => 10,
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
              'name' => 'interpolator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'InterpolatorFactory',
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 35,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 35,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 35,
              'char' => 83,
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
                  'property' => 'defaultInterpolator',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                          'line' => 37,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                        'line' => 37,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'defaultInterpolator',
                          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                          'line' => 37,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                        'line' => 37,
                        'char' => 78,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'associativeArray',
                          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                          'line' => 37,
                          'char' => 96,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                        'line' => 37,
                        'char' => 96,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 37,
                    'char' => 97,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 37,
                  'char' => 97,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'interpolatorFactory',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'interpolator',
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 38,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 38,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 35,
          'last-line' => 45,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '_',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translateKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 46,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 46,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 46,
              'char' => 64,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 48,
                  'char' => 21,
                ),
                'name' => 'query',
                'call-type' => 3,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translateKey',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 48,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 48,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 48,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 48,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 48,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 49,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the translation string of the given key (alias of method \'t\')
     *
     * @param array   placeholders
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
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 47,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 47,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 46,
          'last-line' => 53,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translateKey',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 54,
              'char' => 50,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 56,
                  'char' => 21,
                ),
                'name' => 'exists',
                'call-type' => 3,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translateKey',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 56,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 56,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 56,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether a translation key exists
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
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 55,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 55,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 54,
          'last-line' => 61,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetGet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translateKey',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 62,
              'char' => 47,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 64,
                  'char' => 21,
                ),
                'name' => 'query',
                'call-type' => 3,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translateKey',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 64,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 64,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 64,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 64,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 64,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 65,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the translation related to the given key
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
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 62,
          'last-line' => 71,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetSet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 72,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 72,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'throw',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Exception',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Translate is an immutable ArrayAccess object',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 74,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 74,
                    'char' => 73,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 74,
                'char' => 74,
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 75,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a translation value
     *
     * @param string value
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 73,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 72,
          'last-line' => 79,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetUnset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 80,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'throw',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Exception',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Translate is an immutable ArrayAccess object',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 82,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 82,
                    'char' => 73,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 82,
                'char' => 74,
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Unsets a translation from the dictionary
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 80,
          'last-line' => 89,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 't',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translateKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 90,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 90,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 90,
              'char' => 64,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 92,
                  'char' => 21,
                ),
                'name' => 'query',
                'call-type' => 3,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translateKey',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 92,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 92,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 92,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 92,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 92,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 93,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the translation string of the given key
     *
     * @param array   placeholders
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
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 91,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 91,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 90,
          'last-line' => 97,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'replacePlaceholders',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'translation',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 98,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 98,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 98,
              'char' => 84,
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
                  'variable' => 'interpolator',
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 100,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 102,
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
                  'variable' => 'interpolator',
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
                        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                        'line' => 102,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'interpolatorFactory',
                        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                        'line' => 102,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 102,
                      'char' => 54,
                    ),
                    'name' => 'newInstance',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                            'line' => 102,
                            'char' => 72,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultInterpolator',
                            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                            'line' => 102,
                            'char' => 92,
                          ),
                          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                          'line' => 102,
                          'char' => 92,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                        'line' => 102,
                        'char' => 92,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 102,
                    'char' => 93,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 102,
                  'char' => 93,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 104,
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
                  'value' => 'interpolator',
                  'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                  'line' => 104,
                  'char' => 29,
                ),
                'name' => 'replacePlaceholders',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translation',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 105,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 105,
                    'char' => 24,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                      'line' => 107,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                    'line' => 107,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 107,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Replaces placeholders by the values passed
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
                'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
                'line' => 99,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
            'line' => 99,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
          'line' => 98,
          'last-line' => 109,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
      'line' => 23,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Translate/Adapter/AbstractAdapter.zep',
    'line' => 23,
    'char' => 14,
  ),
);