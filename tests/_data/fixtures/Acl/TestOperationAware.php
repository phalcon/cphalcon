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

use Phalcon\Acl\OperationAware;

/**
 * Class TestOperationAware
 */
class TestOperationAware implements OperationAware
{
    /**
     * @var int
     */
    protected $id;

    /**
     * @var string
     */
    protected $roleName;

    /**
     * @param $id
     * @param $roleName
     */
    public function __construct($id, $roleName)
    {
        $this->id       = $id;
        $this->roleName = $roleName;
    }

    /**
     * @return int
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * @return string
     */
    public function getOperationName(): string
    {
        return $this->roleName;
    }
}
