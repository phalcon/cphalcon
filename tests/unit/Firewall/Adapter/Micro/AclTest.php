<?php

namespace Phalcon\Test\Unit\Firewall\Adapter\Micro;

use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Di;
use Phalcon\Firewall\Adapter\Micro\Acl;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Micro;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Test\Unit\Firewall\Helper\BindingRole;
use Phalcon\Test\Unit\Firewall\Helper\FirewallTrait;
use Phalcon\Mvc\Model\Binder;

/**
 * \Phalcon\Test\Unit\Firewall\Adapter\Micro\AclTest
 * Tests the Phalcon\Firewall\Adapter\Micro\Acl component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Flash
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AclTest extends UnitTest
{
    use FirewallTrait;

    /**
     * @var Micro
     */
    protected $micro;

    /**
     * @var Acl
     */
    protected $firewall;

    /**
     * @var Di
     */
    protected $di;

    public function _before()
    {
        $di = $this->tester->getApplication()->getDI();
        $micro = new Micro($di);
        $micro->get(
            '/test',
            function () {
                return "allowed";
            }
        )->setName('test');
        $micro->get(
            '/test2',
            function () {
                return "allowed";
            }
        )->setName('test2');
        $micro->get(
            '/album/{album}',
            function (Albums $album) {
                return "allowed";
            }
        )->setName('album-get');
        $micro->get(
            '/album/update/{album}',
            function (Albums $album) {
                return "allowed";
            }
        )->setName('album-update');
        $this->micro = $micro;
        $eventsManager = new Manager();
        $eventsManager->attach(
            'firewall:beforeException',
            function () {
                return false;
            }
        );
        $firewall = new Acl('acl');
        $firewall->setEventsManager($eventsManager)
            ->setRoleCallback(
                function ($di) {
                    return $di->get('myrole');
                }
            )
            ->setAlwaysResolvingRole(true);
        $this->firewall = $firewall;
        $this->di = $di;
    }

    public function testBeforeExecute()
    {
        $this->specify(
            "Acl firewall for micro doesn't work correctly for beforeExecute event",
            function () {
                $acl = new Memory();
                $acl->addResource('Micro', ['test', 'test2']);
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addRole('ROLE1');
                $acl->addRole('ROLE2');
                $acl->addRole('ROLE3');
                $acl->addRole('ROLE4');
                $acl->allow('ROLE1', 'Micro', 'test');
                $acl->allow('ROLE2', 'Micro', 'test2');
                $acl->allow('ROLE3', 'Micro', '*');
                $acl->allow('ROLE4', '*', '*');

                $di = $this->di;
                $di->set('acl', $acl);
                $eventsManager = new Manager();
                $eventsManager->attach('micro:beforeExecuteRoute', $this->firewall);
                $this->micro->setEventsManager($eventsManager);
                $micro = $this->micro;

                expect($micro->getDI())->isInstanceOf('Phalcon\Di');
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE1');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE2');
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE3');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE4');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test2', 'ROLE1');
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test2', 'ROLE2');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE3');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE4');
                expect($returnedValue)->equals("allowed");
            }
        );
    }

    public function testAfterBinding()
    {
        $this->specify(
            "Acl firewall for micro doesn't work correctly for afterBinding event",
            function () {
                $acl = new Memory();
                $acl->addResource('Micro', ['album-get', 'album-update']);
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
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

                $di = $this->di;
                $di->set('acl', $acl);
                $eventsManager = new Manager();
                $eventsManager->attach('micro:afterBinding', $this->firewall);
                $this->micro->setEventsManager($eventsManager);
                $binder = new Binder();
                $this->micro->setModelBinder($binder);
                $micro = $this->micro;

                expect($micro->getDI())->isInstanceOf('Phalcon\Di');
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE1", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE1", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE2", 1));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE3", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE3", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE3", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE3", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE2", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE2", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE1", 1));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE4", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE4", 2));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE4", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE4", 2));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE5", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE5", 2));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE5", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE5", 2));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE6", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE6", 2));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE6", 1));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE6", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE7", 1));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE7", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE7", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE7", 2));
                expect($returnedValue)->equals("allowed");
            }
        );
    }

    public function testAfterBindingKeyMap()
    {
        $this->specify(
            "Acl firewall for micro doesn't work correctly for afterBinding event and key map",
            function () {
                $acl = new Memory();
                $acl->addResource('Micro', ['album-get', 'album-update']);
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addRole('ROLE1');
                $acl->addRole('ROLE2');
                $acl->allow(
                    'ROLE1',
                    'Micro',
                    'album-get',
                    function (BindingRole $user, Albums $model) {
                        return $user->getId() == $model->artists_id;
                    }
                );
                $acl->allow(
                    'ROLE2',
                    'Micro',
                    'album-update',
                    function (BindingRole $user, Albums $model) {
                        return $user->getId() == $model->artists_id;
                    }
                );

                $this->firewall->setBoundModelsKeyMap(['album' => 'model']);
                $di = $this->di;
                $di->set('acl', $acl);
                $eventsManager = new Manager();
                $eventsManager->attach('micro:afterBinding', $this->firewall);
                $this->micro->setEventsManager($eventsManager);
                $binder = new Binder();
                $this->micro->setModelBinder($binder);
                $micro = $this->micro;

                expect($micro->getDI())->isInstanceOf('Phalcon\Di');
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE1", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE1", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE2", 1));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE2", 1));
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE2", 2));
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/update/1', new BindingRole("ROLE1", 1));
                expect($returnedValue)->false();
            }
        );
    }

    public function testPatternBeforeExecute()
    {
        $this->specify(
            "Acl firewall for micro doesn't work correctly for beforeExecute event and using patterns",
            function () {
                $acl = new Memory();
                $acl->addResource('Micro', ['/test', '/test2']);
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addRole('ROLE1');
                $acl->addRole('ROLE2');
                $acl->addRole('ROLE3');
                $acl->addRole('ROLE4');
                $acl->allow('ROLE1', 'Micro', '/test');
                $acl->allow('ROLE2', 'Micro', '/test2');
                $acl->allow('ROLE3', 'Micro', '*');
                $acl->allow('ROLE4', '*', '*');

                $di = $this->di;
                $di->set('acl', $acl);
                $eventsManager = new Manager();
                $this->firewall->setRouteNameConfiguration(false);
                $eventsManager->attach('micro:beforeExecuteRoute', $this->firewall);
                $this->micro->setEventsManager($eventsManager);
                $micro = $this->micro;

                expect($micro->getDI())->isInstanceOf('Phalcon\Di');
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE1');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE2');
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE3');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE4');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test2', 'ROLE1');
                expect($returnedValue)->false();
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test2', 'ROLE2');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE3');
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getMicroValueFor($di, $micro, '/test', 'ROLE4');
                expect($returnedValue)->equals("allowed");
            }
        );
    }

    public function testCache()
    {
        $this->specify(
            "Acl firewall with cache for micro doesn't work correctly for afterBinding event",
            function () {
                $acl = new Memory();
                $acl->addResource('Micro', ['album-get']);
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
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

                $di = $this->di;
                $di->set('acl', $acl);
                $eventsManager = new Manager();
                $cache = new Apc(new Data(['lifetime' => 20]));
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

                expect($micro->getDI())->isInstanceOf('Phalcon\Di');
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE1", 1));
                expect($returnedValue)->equals("allowed");
                expect($cache->exists('_PHF_'))->true();
                expect($cache->get('_PHF_')['ROLE1!Micro!album-get!1!1'])->equals(true);
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE1", 2));
                expect($returnedValue)->false();
                expect($cache->get('_PHF_')['ROLE1!Micro!album-get!1!2'])->equals(false);
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE2", 1));
                expect($returnedValue)->equals("allowed");
                expect($cache->get('_PHF_')['ROLE2!Micro!*!1!1'])->equals(true);
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE2", 2));
                expect($returnedValue)->false();
                expect($cache->get('_PHF_')['ROLE2!Micro!*!1!2'])->equals(false);
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE3", 2));
                expect($returnedValue)->equals("allowed");
                expect($cache->get('_PHF_')['ROLE3!*!*'])->equals(true);
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE4", 2));
                expect($returnedValue)->equals("allowed");
                expect($cache->get('_PHF_')['ROLE4!Micro!*'])->equals(true);
                $returnedValue = $this->getMicroValueFor($di, $micro, '/album/1', new BindingRole("ROLE5", 2));
                expect($returnedValue)->equals("allowed");
                expect($cache->get('_PHF_')['ROLE5!Micro!album-get'])->equals(true);
            }
        );
    }
}
