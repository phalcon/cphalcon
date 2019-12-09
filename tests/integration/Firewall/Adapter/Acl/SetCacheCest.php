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
use Phalcon\Cache\AdapterFactory;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Acl;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Firewall\BindingRole;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;
use Phalcon\Test\Models\AlbumORama\Albums;

use function ob_end_clean;
use function ob_start;

class SetCacheCest
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
     * Tests Phalcon\Firewall\Adapter\Acl :: setCache()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAclSetCache(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - setCache()');

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addComponent('Four', ['first', 'second']);
        $acl->addComponent('Three', ['deny',]);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->addRole('ROLE3');
        $acl->addRole('ROLE4');
        $acl->addRole('ROLE5');
        $acl->allow('ROLE1', 'Four', 'first');
        $acl->allow('ROLE1', 'Four', 'second');
        $acl->allow('ROLE1', 'Three', '*');
        $acl->allow('ROLE2', 'Four', 'second');
        $acl->allow(
            'ROLE2',
            'Four',
            'first',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow('ROLE3', '*', '*');
        $acl->allow(
            'ROLE4',
            'Four',
            '*',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow(
            'ROLE5',
            '*',
            '*',
            function (BindingRole $user) {
                return $user->getId() == 3;
            }
        );

        $binder = new Binder();
        $this->dispatcher->setModelBinder($binder);
        $this->container->set('acl', $acl);
        $eventsManager = new Manager();

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $cache      = $factory->newInstance('memory');

        $this->firewall->setCache($cache);
        $this->firewall->setRoleCacheCallback(
            function (BindingRole $user) {
                return $user->getId();
            }
        );
        $eventsManager->attach('dispatch:afterBinding', $this->firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $this->container->set('dispatcher', $dispatcher);

        $examples = [
            [
                'four',
                'first',
                new BindingRole('ROLE1', 1),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE1!Four!first',
                true,
            ],
            [
                'four',
                'first',
                new BindingRole('ROLE1', 2),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE1!Four!first',
                true,
            ],
            [
                'four',
                'first',
                new BindingRole('ROLE2', 1),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE2!Four!first!1!1',
                true,
            ],
            [
                'four',
                'first',
                new BindingRole('ROLE2', 2),
                [
                    'album' => 1,
                ],
                null,
                'ROLE2!Four!first!1!2',
                false,
            ],
            [
                'four',
                'second',
                new BindingRole('ROLE1', 1),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE1!Four!second',
                true,
            ],
            [
                'four',
                'second',
                new BindingRole('ROLE1', 2),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE1!Four!second',
                true,
            ],
            [
                'four',
                'second',
                new BindingRole('ROLE2', 1),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE2!Four!second',
                true,
            ],
            [
                'four',
                'second',
                new BindingRole('ROLE2', 2),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE2!Four!second',
                true,
            ],
            [
                'three',
                'deny',
                new BindingRole('ROLE1', 2),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE1!Three!*',
                true,
            ],
            [
                'four',
                'first',
                new BindingRole('ROLE4', 1),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE4!Four!*!1!1',
                true,
            ],
            [
                'four',
                'first',
                new BindingRole('ROLE4', 2),
                [
                    'album' => 1,
                ],
                null,
                'ROLE4!Four!*!1!2',
                false,
            ],
            [
                'three',
                'deny',
                new BindingRole('ROLE5', 2),
                [
                    'album' => 1,
                ],
                null,
                'ROLE5!*!*!2',
                false,
            ],
            [
                'three',
                'deny',
                new BindingRole('ROLE5', 3),
                [
                    'album' => 1,
                ],
                'allowed',
                'ROLE5!*!*!3',
                true,
            ],
        ];

        foreach ($examples as $example) {
            $returnedValue = $this->getReturnedValueFor(
                $this->container,
                $dispatcher,
                $example[0],
                $example[1],
                $example[2],
                $example[3]
            );
            $I->assertEquals($returnedValue, $example[4]);
            $I->assertEquals($cache->get('_PHF_')[$example[5]], $example[6]);
        }
    }
}
