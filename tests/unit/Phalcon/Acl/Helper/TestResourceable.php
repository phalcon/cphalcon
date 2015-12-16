<?php
/**
 * Created by PhpStorm.
 * User: Wojtek
 * Date: 2015-12-16
 * Time: 23:42
 */

namespace Phalcon\Tests\unit\Phalcon\Acl\Helper;

use Phalcon\Acl\Resourceable;
use Phalcon\Mvc\Model;

class TestResourceable implements Resourceable
{
    protected $user;
    protected $resourceName;

    public function __construct($user, $resourceName)
    {
        $this->user=$user;
        $this->resourceName=$resourceName;
    }

    public function getUser()
    {
        return $this->user;
    }

    public function getResourceName()
    {
        return $this->resourceName;
    }
}