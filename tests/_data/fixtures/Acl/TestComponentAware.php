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

use Phalcon\Acl\ComponentAware;

/**
 * Class TestComponentAware
 */
class TestComponentAware implements ComponentAware
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
        $this->user         = $user;
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
    public function getComponentName(): string
    {
        return $this->resourceName;
    }
}
