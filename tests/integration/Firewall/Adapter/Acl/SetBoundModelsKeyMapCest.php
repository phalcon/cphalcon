<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Firewall\Adapter\Acl;

use IntegrationTester;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Enum;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Acl;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Test\Fixtures\Firewall\BindingRole;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;
use Phalcon\Test\Models\AlbumORama\Albums;

use function ob_end_clean;
use function ob_start;

class SetBoundModelsKeyMapCest
{
    use DiTrait;
    use FirewallTrait;

    /**
     * @var Dispatcher
     */
    protected $dispatcher;

    /**
     * @var Acl
     */
    protected $firewall;

    public function _before()
    {
        ob_start();

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace(
            'Phalcon\Test\Controllers\Firewall'
        );
        $dispatcher->setDI($this->container);
        $eventsManager = new Manager();
        $eventsManager->attach(
            'firewall:beforeException',
            function () {
                return false;
            }
        );
        $firewall = new Acl('acl');
        $firewall->setEventsManager($eventsManager);
        $firewall->setRoleCallback(
            function ($di) {
                return $di->get('myrole');
            }
        );
        $firewall->setAlwaysResolvingRole(true);
        $dispatcher->setEventsManager($eventsManager);
        $this->dispatcher = $dispatcher;
        $this->firewall   = $firewall;
    }

    public function _after()
    {
        ob_end_clean();

        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Firewall\Adapter\Acl :: setBoundModelsKeyMap()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function firewallAdapterAclSetBoundModelsKeyMap(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - setBoundModelsKeyMap()');

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addComponent('Four', ['first', 'second']);
        $acl->addRole('ROLE2');
        $acl->allow(
            'ROLE2',
            'Four',
            'first',
            function (BindingRole $user, Albums $model) {
                return $user->getId() == $model->artists_id;
            }
        );
        $acl->allow('ROLE2', 'Four', 'second');

        $this->container->set('acl', $acl);
        $binder = new Binder();
        $this->dispatcher->setModelBinder($binder);
        $eventsManager = new Manager();
        $this->firewall->setBoundModelsKeyMap(['album' => 'model']);
        $eventsManager->attach('dispatch:afterBinding', $this->firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $this->container->set('dispatcher', $dispatcher);

        $returnedValue = $this->getReturnedValueFor(
            $this->container,
            $dispatcher,
            'four',
            'first',
            new BindingRole('ROLE2', 1),
            ['album' => 1]
        );
        $I->assertEquals($returnedValue, 'allowed');
    }
}
