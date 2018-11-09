<?php

namespace Phalcon\Test\Acl;

use Phalcon\Acl\ResourceAware;

/**
 * TestResourceAware
 * Resource class for \Phalcon\Acl\Resource component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Wojciech Slawski <jurigag@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TestResourceAware implements ResourceAware
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
        $this->user = $user;
        $this->resourceName = $resourceName;
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
