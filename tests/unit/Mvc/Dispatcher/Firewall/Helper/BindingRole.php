<?php
/**
 * Created by PhpStorm.
 * User: Wojtek
 * Date: 2016-04-29
 * Time: 18:36
 */

namespace Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper;

use Phalcon\Acl\RoleAware;

/**
 * \Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\BindingRole
 * Helper class extending Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\RoleObject for firewall tests
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class BindingRole extends RoleObject
{
    protected $id;

    public function __construct($roleName, $id)
    {
        parent::__construct($roleName);
        $this->id=$id;
    }

    /**
     * @return mixed
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * @param mixed $id
     *
     * @return BindingRole
     */
    public function setId($id)
    {
        $this->id = $id;
        return $this;
    }
}
