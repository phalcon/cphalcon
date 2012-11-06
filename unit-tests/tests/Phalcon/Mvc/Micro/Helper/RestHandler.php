<?php
/**
 * RestHandler.php
 * Mvc_Micro_Helper_RestHandler
 *
 * Helper for the Mvc\Micro
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class Mvc_Micro_Helper_RestHandler
{

    protected $_access = 0;

    protected $_trace = array();

    public function find()
    {
        $this->_access++;
        $this->_trace[] = 'find';
    }

    public function save()
    {
        $this->_access++;
        $this->_trace[] = 'save';
    }

    public function getNumberAccess()
    {
        return $this->_access;
    }

    public function getTrace()
    {
        return $this->_trace;
    }
}
