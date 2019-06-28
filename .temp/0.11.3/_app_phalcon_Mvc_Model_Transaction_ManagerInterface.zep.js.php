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
    'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Transaction',
    'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\TransactionInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
        'line' => 13,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Transaction\\Manager
 *',
    'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
    'line' => 20,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'ManagerInterface',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'collectTransactions',
          'docblock' => '**
     * Remove all the transactions from the manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 25,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 25,
          'last-line' => 29,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'commit',
          'docblock' => '**
     * Commits active transactions within the manager
     *',
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 30,
          'last-line' => 34,
          'char' => 19,
        ),
        2 => 
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
              'name' => 'autoBegin',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 35,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
              'line' => 35,
              'char' => 46,
            ),
          ),
          'docblock' => '**
     * Returns a new \\Phalcon\\Mvc\\Model\\Transaction or an already created once
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
                  'value' => 'TransactionInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                  'line' => 35,
                  'char' => 73,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 35,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 35,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 35,
          'last-line' => 39,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDbService',
          'docblock' => '**
     * Returns the database service used to isolate the transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 40,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 40,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 40,
          'last-line' => 44,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRollbackPendent',
          'docblock' => '**
     * Check if the transaction manager is registering a shutdown function to clean up pendent transactions
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 45,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 45,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 45,
          'last-line' => 49,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'docblock' => '**
     * Checks whether manager has an active transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 50,
                'char' => 34,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 50,
            'char' => 34,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 50,
          'last-line' => 54,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notifyCommit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'transaction',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'TransactionInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 55,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
              'line' => 55,
              'char' => 68,
            ),
          ),
          'docblock' => '**
     * Notifies the manager about a committed transaction
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 55,
            'char' => 77,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 55,
          'last-line' => 59,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notifyRollback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'transaction',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'TransactionInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 60,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
              'line' => 60,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Notifies the manager about a rollbacked transaction
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 60,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 60,
          'last-line' => 65,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collect',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 66,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
              'line' => 66,
              'char' => 50,
            ),
          ),
          'docblock' => '**
     * Rollbacks active transactions within the manager
     * Collect will remove transaction from the manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 66,
            'char' => 59,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 66,
          'last-line' => 70,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollbackPendent',
          'docblock' => '**
     * Rollbacks active transactions within the manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 71,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 71,
          'last-line' => 75,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDbService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'service',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
              'line' => 76,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets the database service used to run the isolated transactions
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                  'line' => 76,
                  'char' => 72,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 76,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 76,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRollbackPendent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackPendent',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
              'line' => 81,
              'char' => 60,
            ),
          ),
          'docblock' => '**
     * Set if the transaction manager must register a shutdown function to clean up pendent transactions
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                  'line' => 81,
                  'char' => 83,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
                'line' => 81,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
            'line' => 81,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
          'line' => 81,
          'last-line' => 82,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
      'line' => 82,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/ManagerInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);