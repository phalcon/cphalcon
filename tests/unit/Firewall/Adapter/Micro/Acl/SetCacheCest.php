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

namespace Phalcon\Test\Unit\Firewall\Adapter\Micro\Acl;

use Codeception\Example;
use function ob_end_clean;
use function ob_start;
use Phalcon\Acl as PhAcl;
use Phalcon\Acl\Adapter\Memory;
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
use function sleep;
use UnitTester;

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

    public function _before(UnitTester $I)
    {
        ob_start();

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $micro = new Micro($this->container);
        $micro->get(
            '/test',
            function () {
                return "allowed";
            }
        )->setName('test')
        ;
        $micro->get(
            '/test2',
            function () {
                return "allowed";
            }
        )->setName('test2')
        ;
        $micro->get(
            '/album/{album}',
            function (Albums $album) {
                return "allowed";
            }
        )->setName('album-get')
        ;
        $micro->get(
            '/album/update/{album}',
            function (Albums $album) {
                return "allowed";
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
        $firewall
            ->setEventsManager($eventsManager)
            ->setRoleCallback(
                function ($container) {
                    return $container->get('myrole');
                }
            )
            ->setAlwaysResolvingRole(true)
        ;
        $this->firewall = $firewall;
    }

    public function _after()
    {
        ob_end_clean();
    }

    /**
     * Tests Phalcon\Firewall\Adapter\Micro\Acl :: setCache()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterMicroAclSetCache(UnitTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Micro\Acl - setCache()');

        $acl = new Memory();
        $acl->addComponent('Micro', ['album-get']);
        $acl->setDefaultAction(PhAcl::DENY);
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
            ['/album/1', new BindingRole("ROLE1", 1), "allowed", 'ROLE1!Micro!album-get!1!1', true],
            ['/album/1', new BindingRole("ROLE1", 2), false, 'ROLE1!Micro!album-get!1!2', false],
            ['/album/1', new BindingRole("ROLE2", 1), "allowed", 'ROLE2!Micro!*!1!1', true],
            ['/album/1', new BindingRole("ROLE2", 2), false, 'ROLE2!Micro!*!1!2', false],
            ['/album/1', new BindingRole("ROLE3", 2), "allowed", 'ROLE3!*!*', true],
            ['/album/1', new BindingRole("ROLE4", 2), "allowed", 'ROLE4!Micro!*', true],
            ['/album/1', new BindingRole("ROLE5", 2), "allowed", 'ROLE5!Micro!album-get', true],
        ];

        foreach ($examples as $example) {
            $returnedValue = $this->getMicroValueFor(
                $this->container,
                $micro,
                $example[0],
                $example[1]
            );
            $I->assertEquals($returnedValue, $example[2]);
            $I->assertEquals($cache->get('_PHF_')[$example[3]], $example[4]);
        }
    }
}
