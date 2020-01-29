<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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

    public function __construct($user, string $resourceName)
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

    public function getComponentName(): string
    {
        return $this->resourceName;
    }
}
