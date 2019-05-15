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

namespace Phalcon\Test\Unit\Firewall\Adapter\Micro;

use Codeception\Example;
use Phalcon\Acl as PhAcl;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Cache\Adapter\Stream as StorageStream;
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
use UnitTester;
use function getOptionsModelCacheStream;

class AclCest
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

    /**
     * @dataProvider getBeforeExecute
     *
     * @param UnitTester $I
     * @param Example    $example
     */
    public function testBeforeExecute(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->addComponent('Micro', ['test', 'test2']);
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->addRole('ROLE3');
        $acl->addRole('ROLE4');
        $acl->allow('ROLE1', 'Micro', 'test');
        $acl->allow('ROLE2', 'Micro', 'test2');
        $acl->allow('ROLE3', 'Micro', '*');
        $acl->allow('ROLE4', '*', '*');

        $this->container->set('acl', $acl);
        $eventsManager = new Manager();
        $eventsManager->attach('micro:beforeExecuteRoute', $this->firewall);
        $this->micro->setEventsManager($eventsManager);
        $micro = $this->micro;

        $returnedValue = $this->getMicroValueFor(
            $this->container,
            $micro,
            $example[0],
            $example[1]
        );
        $I->assertEquals($returnedValue, $example[2]);
    }

    /**
     * @dataProvider getAfterBinding
     *
     * @param UnitTester $I
     * @param Example    $example
     */
    public function testAfterBinding(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->addComponent('Micro', ['album-get', 'album-update']);
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->addRole('ROLE3');
        $acl->addRole('ROLE4');
        $acl->addRole('ROLE5');
        $acl->addRole('ROLE6');
        $acl->addRole('ROLE7');
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
            'album-update',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow(
            'ROLE3',
            'Micro',
            '*',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow('ROLE4', '*', '*');
        $acl->allow('ROLE5', 'Micro', '*');
        $acl->allow('ROLE6', 'Micro', 'album-get');
        $acl->allow('ROLE7', 'Micro', 'album-update');

        $this->container->set('acl', $acl);

        $eventsManager = new Manager();
        $eventsManager->attach('micro:afterBinding', $this->firewall);
        $this->micro->setEventsManager($eventsManager);
        $binder = new Binder();
        $this->micro->setModelBinder($binder);
        $micro = $this->micro;

        $returnedValue = $this->getMicroValueFor(
            $this->container,
            $micro,
            $example[0],
            $example[1]
        );
        $I->assertEquals($returnedValue, $example[2]);
    }

    /**
     * @dataProvider getAfterBindingKeyMap
     *
     * @param UnitTester $I
     * @param Example    $example
     */
    public function testAfterBindingKeyMap(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->addComponent('Micro', ['album-get', 'album-update']);
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->allow(
            'ROLE1',
            'Micro',
            'album-get',
            function (BindingRole $user, Albums $model) {
                return $user->getId() == $model->id;
            }
        );
        $acl->allow(
            'ROLE2',
            'Micro',
            'album-update',
            function (BindingRole $user, Albums $model) {
                return $user->getId() == $model->id;
            }
        );

        $this->firewall->setBoundModelsKeyMap(['album' => 'model']);

        $this->container->set('acl', $acl);
        $eventsManager = new Manager();
        $eventsManager->attach('micro:afterBinding', $this->firewall);
        $this->micro->setEventsManager($eventsManager);
        $binder = new Binder();
        $this->micro->setModelBinder($binder);
        $micro = $this->micro;

        $returnedValue = $this->getMicroValueFor(
            $this->container,
            $micro,
            $example[0],
            $example[1]
        );
        $I->assertEquals($returnedValue, $example[2]);
    }

    /**
     * @dataProvider getPatternBeforeExecute
     *
     * @param UnitTester $I
     * @param Example    $example
     */
    public function testPatternBeforeExecute(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->addComponent('Micro', ['/test', '/test2']);
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->addRole('ROLE3');
        $acl->addRole('ROLE4');
        $acl->allow('ROLE1', 'Micro', '/test');
        $acl->allow('ROLE2', 'Micro', '/test2');
        $acl->allow('ROLE3', 'Micro', '*');
        $acl->allow('ROLE4', '*', '*');

        $this->container->set('acl', $acl);
        $eventsManager = new Manager();
        $this->firewall->setRouteNameConfiguration(false);
        $eventsManager->attach('micro:beforeExecuteRoute', $this->firewall);
        $this->micro->setEventsManager($eventsManager);
        $micro = $this->micro;

        $returnedValue = $this->getMicroValueFor(
            $this->container,
            $micro,
            $example[0],
            $example[1]
        );
        $I->assertEquals($returnedValue, $example[2]);
    }

    /**
     * @dataProvider getCache
     *
     * @param UnitTester $I
     * @param Example    $example
     */
    public function testCache(UnitTester $I, Example $example)
    {
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

        $serializer   = new SerializerFactory();
        $factory      = new AdapterFactory($serializer);
        $cache        = $factory->newInstance('memory');

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

        $returnedValue = $this->getMicroValueFor(
            $this->container,
            $micro,
            $example[0],
            $example[1]
        );
        $I->assertEquals($returnedValue, $example[2]);
        $I->assertEquals($cache->get('_PHF_')[$example[3]], $example[4]);
    }

    /**
     * @return array
     */
    private function getBeforeExecute(): array
    {
        return [
            ['/test', 'ROLE1', "allowed"],
            ['/test', 'ROLE2', null],
            ['/test', 'ROLE3', "allowed"],
            ['/test', 'ROLE4', "allowed"],
            ['/test2', 'ROLE1', null],
            ['/test2', 'ROLE2', "allowed"],
            ['/test', 'ROLE3', "allowed"],
            ['/test', 'ROLE4', "allowed"],
        ];
    }

    /**
     * @return array
     */
    private function getAfterBinding(): array
    {
        return [
            ['/album/1', new BindingRole("ROLE1", 1), "allowed"],
            ['/album/1', new BindingRole("ROLE1", 2), false],
            ['/album/1', new BindingRole("ROLE2", 1), false],
            ['/album/update/1', new BindingRole("ROLE3", 1), "allowed"],
            ['/album/1', new BindingRole("ROLE3", 1), "allowed"],
            ['/album/update/1', new BindingRole("ROLE3", 2), false],
            ['/album/1', new BindingRole("ROLE3", 2), false],
            ['/album/update/1', new BindingRole("ROLE2", 1), "allowed"],
            ['/album/update/1', new BindingRole("ROLE2", 2), false],
            ['/album/update/1', new BindingRole("ROLE1", 1), false],
            ['/album/1', new BindingRole("ROLE4", 1), "allowed"],
            ['/album/1', new BindingRole("ROLE4", 2), "allowed"],
            ['/album/update/1', new BindingRole("ROLE4", 1), "allowed"],
            ['/album/update/1', new BindingRole("ROLE4", 2), "allowed"],
            ['/album/1', new BindingRole("ROLE5", 1), "allowed"],
            ['/album/1', new BindingRole("ROLE5", 2), "allowed"],
            ['/album/update/1', new BindingRole("ROLE5", 1), "allowed"],
            ['/album/update/1', new BindingRole("ROLE5", 2), "allowed"],
            ['/album/1', new BindingRole("ROLE6", 1), "allowed"],
            ['/album/1', new BindingRole("ROLE6", 2), "allowed"],
            ['/album/update/1', new BindingRole("ROLE6", 1), false],
            ['/album/update/1', new BindingRole("ROLE6", 2), false],
            ['/album/1', new BindingRole("ROLE7", 1), false],
            ['/album/1', new BindingRole("ROLE7", 2), false],
            ['/album/update/1', new BindingRole("ROLE7", 1), "allowed"],
            ['/album/update/1', new BindingRole("ROLE7", 2), "allowed"],
        ];
    }

    /**
     * @return array
     */
    private function getAfterBindingKeyMap(): array
    {
        return [
            ['/album/1', new BindingRole("ROLE1", 1), "allowed"],
            ['/album/1', new BindingRole("ROLE1", 2), false],
            ['/album/1', new BindingRole("ROLE2", 1), false],
            ['/album/update/1', new BindingRole("ROLE2", 1), "allowed"],
            ['/album/update/1', new BindingRole("ROLE2", 2), false],
            ['/album/update/1', new BindingRole("ROLE1", 1), false],
        ];
    }

    /**
     * @return array
     */
    private function getPatternBeforeExecute(): array
    {
        return [
            ['/test', 'ROLE1', "allowed"],
            ['/test', 'ROLE2', false],
            ['/test', 'ROLE3', "allowed"],
            ['/test', 'ROLE4', "allowed"],
            ['/test2', 'ROLE1', false],
            ['/test2', 'ROLE2', "allowed"],
            ['/test', 'ROLE3', "allowed"],
            ['/test', 'ROLE4', "allowed"],
        ];
    }

    /**
     * @return array
     */
    private function getCache(): array
    {
        return [
            ['/album/1', new BindingRole("ROLE1", 1), "allowed", 'ROLE1!Micro!album-get!1!1', true],
            ['/album/1', new BindingRole("ROLE1", 2), false, 'ROLE1!Micro!album-get!1!2', false],
            ['/album/1', new BindingRole("ROLE2", 1), "allowed", 'ROLE2!Micro!*!1!1', true],
            ['/album/1', new BindingRole("ROLE2", 2), false, 'ROLE2!Micro!*!1!2', false],
            ['/album/1', new BindingRole("ROLE3", 2), "allowed", 'ROLE3!*!*', true],
            ['/album/1', new BindingRole("ROLE4", 2), "allowed", 'ROLE4!Micro!*', true],
            ['/album/1', new BindingRole("ROLE5", 2), "allowed", 'ROLE5!Micro!album-get', true],
         ];
    }
}
