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
    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation\\Validator',
    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
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
        'name' => 'Phalcon\\Validation\\Validation',
        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
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
        'name' => 'Phalcon\\Validation\\AbstractValidator',
        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
        'line' => 14,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
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
        'name' => 'Phalcon\\Messages\\Message',
        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
        'line' => 15,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
    'line' => 67,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Check for IP addresses
 *
 * ```php
 * use Phalcon\\Validation\\Validator\\Ip as IpValidator;
 *
 * $validator->add(
 *     "ip_address",
 *     new IpValidator(
 *         [
 *             "message"       => ":field must contain only ip addresses",
 *             "version"       => IP::VERSION_4 | IP::VERSION_6, // v6 and v4. The same if not specified
 *             "allowReserved" => false,   // False if not specified. Ignored for v6
 *             "allowPrivate"  => false,   // False if not specified
 *             "allowEmpty"    => false,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "source_address",
 *         "destination_address",
 *     ],
 *     new IpValidator(
 *         [
 *             "message" => [
 *                 "source_address"      => "source_address must be a valid IP address",
 *                 "destination_address" => "destination_address must be a valid IP address",
 *             ],
 *             "version" => [
 *                  "source_address"      => Ip::VERSION_4 | IP::VERSION_6,
 *                  "destination_address" => Ip::VERSION_4,
 *             ],
 *             "allowReserved" => [
 *                  "source_address"      => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowPrivate" => [
 *                  "source_address"      => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowEmpty" => [
 *                  "source_address"      => false,
 *                  "destination_address" => true,
 *             ],
 *         ]
 *     )
 * );
 * ```
 *',
    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
    'line' => 68,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Ip',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractValidator',
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
          'name' => 'template',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Field :field must be a valid IP address',
            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
            'line' => 73,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
          'line' => 77,
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
          'name' => 'validate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'validation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Validation',
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 78,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 78,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 78,
              'char' => 64,
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
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 80,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'version',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 80,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'allowPrivate',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 80,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'allowReserved',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 80,
                  'char' => 56,
                ),
                4 => 
                array (
                  'variable' => 'allowEmpty',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 80,
                  'char' => 68,
                ),
                5 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 80,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 82,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 82,
                      'char' => 32,
                    ),
                    'name' => 'getValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 82,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 82,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 82,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 82,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'version',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 83,
                      'char' => 28,
                    ),
                    'name' => 'getOption',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'version',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 83,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 83,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bitwise_or',
                          'left' => 
                          array (
                            'type' => 'constant',
                            'value' => 'FILTER_FLAG_IPV4',
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 83,
                            'char' => 65,
                          ),
                          'right' => 
                          array (
                            'type' => 'constant',
                            'value' => 'FILTER_FLAG_IPV6',
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 83,
                            'char' => 83,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 83,
                          'char' => 83,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 83,
                        'char' => 83,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 83,
                    'char' => 84,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 83,
                  'char' => 84,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 85,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'version',
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 85,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 85,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 85,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 85,
                'char' => 36,
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
                      'variable' => 'version',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'version',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 86,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 86,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 86,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 86,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 87,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 89,
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
                  'variable' => 'allowPrivate',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 89,
                        'char' => 33,
                      ),
                      'name' => 'getOption',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'allowPrivate',
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 89,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 89,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 89,
                      'char' => 58,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 89,
                      'char' => 62,
                    ),
                    'extra' => 
                    array (
                      'type' => 'constant',
                      'value' => 'FILTER_FLAG_NO_PRIV_RANGE',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 89,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 89,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 89,
                  'char' => 89,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 91,
              'char' => 10,
            ),
            4 => 
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
                    'value' => 'allowPrivate',
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 91,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 91,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 91,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 91,
                'char' => 41,
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
                      'variable' => 'allowPrivate',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'allowPrivate',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 92,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 92,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 92,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 92,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 95,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'allowReserved',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 95,
                        'char' => 34,
                      ),
                      'name' => 'getOption',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'allowReserved',
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 95,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 95,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 95,
                      'char' => 60,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 95,
                      'char' => 64,
                    ),
                    'extra' => 
                    array (
                      'type' => 'constant',
                      'value' => 'FILTER_FLAG_NO_RES_RANGE',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 95,
                      'char' => 90,
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 95,
                    'char' => 90,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 95,
                  'char' => 90,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 97,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'allowReserved',
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 97,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 97,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 97,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 97,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'allowReserved',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'allowReserved',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 98,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'field',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 98,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 98,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 98,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 99,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 101,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'allowEmpty',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 101,
                      'char' => 31,
                    ),
                    'name' => 'getOption',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'allowEmpty',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 101,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 101,
                        'char' => 52,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 101,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 101,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 101,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 101,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 103,
              'char' => 10,
            ),
            8 => 
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
                    'value' => 'allowEmpty',
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 103,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 103,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 103,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 103,
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
                      'variable' => 'allowEmpty',
                      'expr' => 
                      array (
                        'type' => 'ternary',
                        'left' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'allowEmpty',
                              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                              'line' => 104,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'field',
                              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                              'line' => 104,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 104,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 104,
                          'char' => 54,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'allowEmpty',
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 104,
                            'char' => 66,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'field',
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 104,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 104,
                          'char' => 74,
                        ),
                        'extra' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 104,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 104,
                        'char' => 81,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 104,
                      'char' => 81,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 105,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 107,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'allowEmpty',
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 107,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 107,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 107,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 107,
                'char' => 38,
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
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 108,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 109,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 111,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'options',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 112,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'array',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'key' => 
                              array (
                                'type' => 'string',
                                'value' => 'default',
                                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                                'line' => 113,
                                'char' => 24,
                              ),
                              'value' => 
                              array (
                                'type' => 'bool',
                                'value' => 'false',
                                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                                'line' => 114,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                              'line' => 114,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 114,
                          'char' => 14,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 114,
                        'char' => 14,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'flags',
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 115,
                          'char' => 18,
                        ),
                        'value' => 
                        array (
                          'type' => 'bitwise_or',
                          'left' => 
                          array (
                            'type' => 'bitwise_or',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'version',
                              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                              'line' => 115,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'allowPrivate',
                              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                              'line' => 115,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 115,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'allowReserved',
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 116,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 116,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 116,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 116,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 116,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 118,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'filter_var',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 118,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 118,
                      'char' => 29,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'constant',
                        'value' => 'FILTER_VALIDATE_IP',
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 118,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 118,
                      'char' => 49,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 118,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 118,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 118,
                  'char' => 60,
                ),
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 118,
                'char' => 60,
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
                      'value' => 'validation',
                      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                      'line' => 119,
                      'char' => 24,
                    ),
                    'name' => 'appendMessage',
                    'call-type' => 1,
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
                            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                            'line' => 120,
                            'char' => 22,
                          ),
                          'name' => 'messageFactory',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'validation',
                                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                                'line' => 120,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                              'line' => 120,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'field',
                                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                                'line' => 120,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                              'line' => 120,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                          'line' => 121,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                        'line' => 121,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 121,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 123,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                    'line' => 123,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                  'line' => 124,
                  'char' => 8,
                ),
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 126,
              'char' => 14,
            ),
            12 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 126,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Validation/Validator/Ip.zep',
              'line' => 127,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Executes the validation
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
                'file' => '/app/phalcon/Validation/Validator/Ip.zep',
                'line' => 79,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
          'line' => 78,
          'last-line' => 128,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'VERSION_4',
          'default' => 
          array (
            'type' => 'constant',
            'value' => 'FILTER_FLAG_IPV4',
            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
            'line' => 70,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
          'line' => 71,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'VERSION_6',
          'default' => 
          array (
            'type' => 'constant',
            'value' => 'FILTER_FLAG_IPV6',
            'file' => '/app/phalcon/Validation/Validator/Ip.zep',
            'line' => 71,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Validation/Validator/Ip.zep',
          'line' => 73,
          'char' => 13,
        ),
      ),
      'file' => '/app/phalcon/Validation/Validator/Ip.zep',
      'line' => 68,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Validation/Validator/Ip.zep',
    'line' => 68,
    'char' => 5,
  ),
);