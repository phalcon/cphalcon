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

namespace Phalcon\Test\Controllers\Firewall;

use Phalcon\Mvc\Controller;

class OneController extends Controller
{
    /**
     * @Allow("ROLE1")
     */
    public function firstRoleAction()
    {
        return 'allowed';
    }

    /**
     * @Deny("ROLE1")
     */
    public function secondRoleAction()
    {
        return 'allowed';
    }

    /**
     * @Allow({"ROLE1","ROLE2"})
     */
    public function firstArrayAction()
    {
        return 'allowed';
    }

    /**
     * @Deny({"ROLE1","ROLE2"})
     */
    public function secondArrayAction()
    {
        return 'allowed';
    }

    /**
     * @Allow()
     */
    public function allowEveryoneAction()
    {
        return 'allowed';
    }

    /**
     * @Deny()
     */
    public function denyEveryoneAction()
    {
        return 'allowed';
    }
}
