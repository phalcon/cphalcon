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
    'file' => '/app/phalcon/Forms/Manager.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Forms',
    'file' => '/app/phalcon/Forms/Manager.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Forms Manager
 *',
    'file' => '/app/phalcon/Forms/Manager.zep',
    'line' => 16,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Manager',
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
          'name' => 'forms',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Forms/Manager.zep',
            'line' => 18,
            'char' => 25,
          ),
          'file' => '/app/phalcon/Forms/Manager.zep',
          'line' => 24,
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
          'name' => 'create',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 25,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'entity',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 25,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 25,
              'char' => 54,
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
                  'variable' => 'form',
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 27,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 29,
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
                  'variable' => 'form',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Form',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'entity',
                          'file' => '/app/phalcon/Forms/Manager.zep',
                          'line' => 29,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Forms/Manager.zep',
                        'line' => 29,
                        'char' => 35,
                      ),
                    ),
                    'file' => '/app/phalcon/Forms/Manager.zep',
                    'line' => 29,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 29,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'forms',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Forms/Manager.zep',
                      'line' => 30,
                      'char' => 29,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'form',
                    'file' => '/app/phalcon/Forms/Manager.zep',
                    'line' => 30,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 30,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 32,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'form',
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 32,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 33,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Creates a form registering it in the forms manager
     *
     * @param object entity
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
                  'value' => 'Form',
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 26,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 26,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Manager.zep',
            'line' => 26,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Manager.zep',
          'line' => 25,
          'last-line' => 37,
          'char' => 19,
        ),
        1 => 
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 38,
              'char' => 36,
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
                  'variable' => 'form',
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 40,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 42,
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
                      'value' => 'form',
                      'file' => '/app/phalcon/Forms/Manager.zep',
                      'line' => 42,
                      'char' => 52,
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
                          'file' => '/app/phalcon/Forms/Manager.zep',
                          'line' => 42,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'forms',
                          'file' => '/app/phalcon/Forms/Manager.zep',
                          'line' => 42,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Forms/Manager.zep',
                        'line' => 42,
                        'char' => 45,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Forms/Manager.zep',
                        'line' => 42,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Forms/Manager.zep',
                      'line' => 42,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Forms/Manager.zep',
                    'line' => 42,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 42,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 42,
                'char' => 52,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'There is no form with name=\'',
                              'file' => '/app/phalcon/Forms/Manager.zep',
                              'line' => 43,
                              'char' => 62,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Forms/Manager.zep',
                              'line' => 43,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Forms/Manager.zep',
                            'line' => 43,
                            'char' => 69,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\'',
                            'file' => '/app/phalcon/Forms/Manager.zep',
                            'line' => 43,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Forms/Manager.zep',
                          'line' => 43,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Forms/Manager.zep',
                        'line' => 43,
                        'char' => 72,
                      ),
                    ),
                    'file' => '/app/phalcon/Forms/Manager.zep',
                    'line' => 43,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 44,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 46,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'form',
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 46,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 47,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a form by its name
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
                  'value' => 'Form',
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 39,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 39,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Manager.zep',
            'line' => 39,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Manager.zep',
          'line' => 38,
          'last-line' => 51,
          'char' => 19,
        ),
        2 => 
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 52,
              'char' => 36,
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Forms/Manager.zep',
                      'line' => 54,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'forms',
                      'file' => '/app/phalcon/Forms/Manager.zep',
                      'line' => 54,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Forms/Manager.zep',
                    'line' => 54,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Forms/Manager.zep',
                    'line' => 54,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 54,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 54,
                'char' => 39,
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a form is registered in the forms manager
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
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 53,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Manager.zep',
            'line' => 53,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Manager.zep',
          'line' => 52,
          'last-line' => 59,
          'char' => 19,
        ),
        3 => 
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 60,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'form',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Form',
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 60,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 60,
              'char' => 49,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'forms',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Forms/Manager.zep',
                      'line' => 62,
                      'char' => 29,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'form',
                    'file' => '/app/phalcon/Forms/Manager.zep',
                    'line' => 62,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 62,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 64,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 64,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Forms/Manager.zep',
              'line' => 65,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Registers a form in the Forms Manager
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
                  'value' => 'FormManager',
                  'file' => '/app/phalcon/Forms/Manager.zep',
                  'line' => 61,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/Manager.zep',
                'line' => 61,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Manager.zep',
            'line' => 61,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Manager.zep',
          'line' => 60,
          'last-line' => 66,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Forms/Manager.zep',
      'line' => 16,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Forms/Manager.zep',
    'line' => 16,
    'char' => 5,
  ),
);