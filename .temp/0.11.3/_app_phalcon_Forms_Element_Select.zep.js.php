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
    'file' => '/app/phalcon/Forms/Element/Select.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Forms\\Element',
    'file' => '/app/phalcon/Forms/Element/Select.zep',
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
        'name' => 'Phalcon\\Forms\\Element',
        'file' => '/app/phalcon/Forms/Element/Select.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Forms/Element/Select.zep',
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
        'name' => 'Phalcon\\Tag\\Select',
        'file' => '/app/phalcon/Forms/Element/Select.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Forms/Element/Select.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Forms\\Element\\Select
 *
 * Component SELECT (choice) for forms
 *',
    'file' => '/app/phalcon/Forms/Element/Select.zep',
    'line' => 21,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Select',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Element',
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
          'name' => 'optionsValues',
          'file' => '/app/phalcon/Forms/Element/Select.zep',
          'line' => 30,
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 31,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 31,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 31,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 31,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 31,
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'optionsValues',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 33,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 33,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 35,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Forms/Element/Select.zep',
                      'line' => 35,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 35,
                    'char' => 33,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attributes',
                      'file' => '/app/phalcon/Forms/Element/Select.zep',
                      'line' => 35,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 35,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 35,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 36,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Forms\\Element constructor
     *
     * @param object|array options
     * @param array        attributes
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Forms/Element/Select.zep',
            'line' => 32,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Element/Select.zep',
          'line' => 31,
          'last-line' => 42,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'option',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 43,
              'char' => 41,
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
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 45,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 45,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 47,
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
                    'value' => 'option',
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 47,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 47,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 47,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 47,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'option',
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 48,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'optionsValues',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Forms/Element/Select.zep',
                              'line' => 49,
                              'char' => 44,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Forms/Element/Select.zep',
                            'line' => 49,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Forms/Element/Select.zep',
                          'line' => 49,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Forms/Element/Select.zep',
                      'line' => 50,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 51,
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
                      'assign-type' => 'object-property-append',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'optionsValues',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'option',
                        'file' => '/app/phalcon/Forms/Element/Select.zep',
                        'line' => 52,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Forms/Element/Select.zep',
                      'line' => 52,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 53,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 55,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 55,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 56,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an option to the current options
     *
     * @param array option
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
                  'value' => 'Element',
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 44,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 44,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Element/Select.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Element/Select.zep',
          'line' => 43,
          'last-line' => 62,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOptions',
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
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 65,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'optionsValues',
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 65,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 65,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 66,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the choices\' options
     *
     * @return array|object
     *',
          'file' => '/app/phalcon/Forms/Element/Select.zep',
          'line' => 63,
          'last-line' => 70,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'render',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 71,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 71,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'Select',
                'dynamic' => 0,
                'name' => 'selectField',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Forms/Element/Select.zep',
                        'line' => 77,
                        'char' => 18,
                      ),
                      'name' => 'prepareAttributes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attributes',
                            'file' => '/app/phalcon/Forms/Element/Select.zep',
                            'line' => 77,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Forms/Element/Select.zep',
                          'line' => 77,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Forms/Element/Select.zep',
                      'line' => 77,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 77,
                    'char' => 48,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Forms/Element/Select.zep',
                        'line' => 78,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'optionsValues',
                        'file' => '/app/phalcon/Forms/Element/Select.zep',
                        'line' => 79,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Forms/Element/Select.zep',
                      'line' => 79,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 79,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 79,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders the element widget returning html
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
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 72,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Element/Select.zep',
            'line' => 72,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Element/Select.zep',
          'line' => 71,
          'last-line' => 86,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 87,
              'char' => 43,
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
                  'property' => 'optionsValues',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Forms/Element/Select.zep',
                    'line' => 89,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 89,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 91,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 91,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Forms/Element/Select.zep',
              'line' => 92,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the choice\'s options
     *
     * @param array|object options
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
                  'value' => 'Element',
                  'file' => '/app/phalcon/Forms/Element/Select.zep',
                  'line' => 88,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/Element/Select.zep',
                'line' => 88,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/Element/Select.zep',
            'line' => 88,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Forms/Element/Select.zep',
          'line' => 87,
          'last-line' => 93,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Forms/Element/Select.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Forms/Element/Select.zep',
    'line' => 21,
    'char' => 5,
  ),
);