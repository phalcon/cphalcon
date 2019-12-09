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

namespace Phalcon\Test\Integration\Firewall\Adapter\Micro\Acl;

use IntegrationTester;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Enum;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Micro\Acl;
use Phalcon\Mvc\Micro;
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
     * @var Micro
     */
    protected $micro;

    /**
     * @var Acl
     */
    protected $firewall;

    public function _before(IntegrationTester $I)
    {
        ob_start();

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $micro = new Micro($this->container);
        $micro->get(
            '/test',
            function () {
                return 'allowed';
            }
        )->setName('test')
        ;
        $micro->get(
            '/test2',
            function () {
                return 'allowed';
            }
        )->setName('test2')
        ;
        $micro->get(
            '/album/{album}',
            function (Albums $album) {
                return 'allowed';
            }
        )->setName('album-get')
        ;
        $micro->get(
            '/album/update/{album}',
            function (Albums $album) {
                return 'allowed';
            }
        )->setName('album-update')
        ;
        $this->micro   = $micro;
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
            function ($container) {
                return $container->get('myrole');
            }
        );
        $firewall->setAlwaysResolvingRole(true);
        $this->firewall = $firewall;
    }

    public function _after()
    {
        ob_end_clean();

        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Firewall\Adapter\Micro\Acl :: setCache()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterMicroAclSetCache(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Micro\Acl - setCache()');

        $acl = new Memory();
        $acl->addComponent('Micro', ['album-get']);
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->addRole('ROLE3');
        $acl->addRole('ROLE4');
        $acl->addRole('ROLE5');
        $acl->allow(
            'ROLE1',
            'Micro',
            'album-get',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow(
            'ROLE2',
            'Micro',
            '*',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow('ROLE3', '*', '*');
        $acl->allow('ROLE4', 'Micro', '*');
        $acl->allow('ROLE5', 'Micro', 'album-get');

        $this->container->set('acl', $acl);
        $eventsManager = new Manager();

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $cache      = $factory->newInstance('memory');

        $this->firewall->setRoleCacheCallback(
            function (BindingRole $user) {
                return $user->getId();
            }
        );
        $this->firewall->setCache($cache);
        $eventsManager->attach('micro:afterBinding', $this->firewall);
        $this->micro->setEventsManager($eventsManager);
        $binder = new Binder();
        $this->micro->setModelBinder($binder);
        $micro = $this->micro;

        $examples = [
            [
                '/album/1',
                new BindingRole('ROLE1', 1),
                'allowed',
                'ROLE1!Micro!album-get!1!1',
                true,
            ],
            [
                '/album/1',
                new BindingRole('ROLE1', 2),
                false,
                'ROLE1!Micro!album-get!1!2',
                false,
            ],
            [
                '/album/1',
                new BindingRole('ROLE2', 1),
                'allowed',
                'ROLE2!Micro!*!1!1',
                true,
            ],
            [
                '/album/1',
                new BindingRole('ROLE2', 2),
                false,
                'ROLE2!Micro!*!1!2',
                false,
            ],
            [
                '/album/1',
                new BindingRole('ROLE3', 2),
                'allowed',
                'ROLE3!*!*',
                true,
            ],
            [
                '/album/1',
                new BindingRole('ROLE4', 2),
                'allowed',
                'ROLE4!Micro!*',
                true,
            ],
            [
                '/album/1',
                new BindingRole('ROLE5', 2),
                'allowed',
                'ROLE5!Micro!album-get',
                true,
            ],
        ];

        foreach ($examples as $example) {
            $returnedValue = $this->getMicroValueFor(
                $this->container,
                $micro,
                $example[0],
                $example[1]
            );

            $I->assertEquals(
                $example[2],
                $returnedValue
            );

            $I->assertEquals(
                $example[4],
                $cache->get('_PHF_')[$example[3]]
            );
        }
    }
}
