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

namepsace Phalcon\Annotations\Adapter;

/**
* Phalcon\Annotations\Adapter\Apc
*
* Stores the parsed annotations in APC. This adapter is suitable for production
*
*<code>
* $annotations = new \Phalcon\Annotations\Adapter\Apc();
*</code>
*/

class Apc 
{
  /**
  * Reads parsed annotations from APC
  *
  * @param string $key
  * @return Phalcon\Annotations\Reflection
  */
  public function read(key)
  {
    var prefixedKey, prefixedLower;
    
    let prefixedKey = "_PHAN" . key;
    let prefixedLower = strtolower(prefixedKey);
    return apc_fetch(prefixedLower); 
  }
  
  /**
  * Writes parsed annotations to APC
  *
  * @param string $key
  * @param Phalcon\Annotations\Reflection $data
  */
  public function write(key, data)
  {
    var prefixedKey, prefixedLower;
    
    let prefixedKey = "_PHAN" . key;
    let prefixedLower = strtolower(prefixedKey);
    return apc_store(prefixedLower, data); 
  }
}
