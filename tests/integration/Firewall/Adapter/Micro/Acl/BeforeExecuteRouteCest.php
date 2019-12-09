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
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Micro\Acl;
use Phalcon\Mvc\Micro;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;
use Phalcon\Test\Models\AlbumORama\Albums;

use function ob_end_clean;
use function ob_start;

class BeforeExecuteRouteCest
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

        $this->micro = $micro;

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
     * Tests Phalcon\Firewall\Adapter\Micro\Acl :: beforeExecuteRoute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterMicroAclBeforeExecuteRoute(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Micro\Acl - beforeExecuteRoute()');

        $acl = new Memory();

        $acl->addComponent(
            'Micro',
            [
                'test',
                'test2',
            ]
        );

        $acl->setDefaultAction(Enum::DENY);

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

        $examples = [
            ['/test', 'ROLE1', 'allowed'],
            ['/test', 'ROLE2', null],
            ['/test', 'ROLE3', 'allowed'],
            ['/test', 'ROLE4', 'allowed'],
            ['/test2', 'ROLE1', null],
            ['/test2', 'ROLE2', 'allowed'],
            ['/test', 'ROLE3', 'allowed'],
            ['/test', 'ROLE4', 'allowed'],
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
        }
    }
}
