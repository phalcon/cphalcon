/*
+------------------------------------------------------------------------+
| Phalcon Framework                                                      |
+------------------------------------------------------------------------+
| Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
+------------------------------------------------------------------------+
| This source file is subject to the New BSD License that is bundled     |
| with this package in the file docs/LICENSE.txt.                        |
|                                                                        |
| If you did not receive a copy of the license and are unable to         |
| obtain it through the world-wide-web, please send an email             |
| to license@phalconphp.com so we can send you a copy immediately.       |
+------------------------------------------------------------------------+
| Authors: Andres Gutierrez <andres@phalconphp.com>                      |
|          Eduar Carvajal <eduar@phalconphp.com>                         |
+------------------------------------------------------------------------+
*/

namespace Phalcon\Annotations\Adapter;

/**
* Phalcon\Annotations\Adapter\Memory
*
* Stores the parsed annotations in memory. This adapter is the suitable development/testing
*/
class Memory 
{
  /**
  * Data
  * @var mixed
  */
  protected _data;
  
  /**
  * Reads parsed annotations from memory
  *
  * @param string $key
  * @return Phalcon\Annotations\Reflection
  */
  public function read(key)
  {
    var data, lowercasedKey;
    
    let data = this->_data;
    let lowercasedKey = strtolower(key);
    if isset data[lowercasedKey] {
      return data[lowercasedKey];
    }
  }
  
  /**
  * Writes parsed annotations to memory
  *
  * @param string $key
  * @param Phalcon\Annotations\Reflection $data
  */
  public function write(key, data)
  {
    var lowercasedKey;
    
    let lowercasedKey = strtolower(key);
    let this->_data[lowercasedKey] = data;
  }
}
