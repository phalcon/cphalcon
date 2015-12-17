<?php
/**
 * Created by PhpStorm.
 * User: Wojtek
 * Date: 2015-12-16
 * Time: 23:42
 */

namespace Phalcon\Tests\unit\Phalcon\Acl\Helper;

use Phalcon\Acl\Resourceable;

/**
 * Class TestResourceable for AclMemoryTest::testAclAllowFunction
 * @package Phalcon\Tests\unit\Phalcon\Acl\Helper
 * @author Wojciech Slawski <jurigag@gmail.com>
 * @since  2015-12-16
 */
class TestResourceable implements Resourceable
{
    /**
     * @var int
     */
    protected $user;
    /**
     * @var string
     */
    protected $resourceName;

    /**
     * @param $user
     * @param $resourceName
     */
    public function __construct($user, $resourceName)
    {
        $this->user=$user;
        $this->resourceName=$resourceName;
    }

    /**
     * @return int
     */
    public function getUser()
    {
        return $this->user;
    }

    /**
     * @return string
     */
    public function getResourceName()
    {
        return $this->resourceName;
    }
}
