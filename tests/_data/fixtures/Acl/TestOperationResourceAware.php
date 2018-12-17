<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Acl;

use Phalcon\Acl\ResourceAware;
use Phalcon\Acl\OperationAware;

/**
 * Class TestOperationResourceAware
 */
class TestOperationResourceAware implements OperationAware, ResourceAware
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
     * @var string
     */
    protected $roleName;

    /**
     * @param $user
     * @param $resourceName
     * @param $roleName
     */
    public function __construct($user, $resourceName, $roleName)
    {
        $this->user         = $user;
        $this->resourceName = $resourceName;
        $this->roleName     = $roleName;
    }

    /**
     * @return string
     */
    public function getResourceName(): string
    {
        return $this->resourceName;
    }

    /**
     * @return string
     */
    public function getOperationName(): string
    {
        return $this->roleName;
    }

    /**
     * @return int
     */
    public function getUser()
    {
        return $this->user;
    }
}
