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
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Micro\Acl;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Test\Fixtures\Firewall\BindingRole;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use UnitTester;

class SetBoundModelsKeyMapCest
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
     * Tests Phalcon\Firewall\Adapter\Micro\Acl :: setBoundModelsKeyMap()
     *
     * @dataProvider getAfterBindingKeyMap
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterMicroAclSetBoundModelsKeyMap(UnitTester $I, Example $example)
    {
        $I->wantToTest('Firewall\Adapter\Micro\Acl - setBoundModelsKeyMap()');

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
}
