<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Mvc\Model\Manager;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\Model\ManagerTest
 * Tests the Phalcon\Mvc\Model\Manager component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ManagerTest extends UnitTest
{
    /**
     * @var Manager
     */
    private $modelsManager;

    protected function _before()
    {
        parent::_before();

        /** @var \Phalcon\Mvc\Application $app */
        $app = $this->tester->getApplication();
        $this->modelsManager = $app->getDI()->getShared('modelsManager');
    }

    public function testAliasedNamespacesRelations()
    {
        $this->specify(
            "Aliased namespaces should work in relations",
            function () {
                $this->modelsManager->registerNamespaceAlias('AlbumORama','Phalcon\Test\Models\AlbumORama');
                $albums = Albums::find();
                foreach($albums as $album){
                    expect($album->artist)->isInstanceOf('Phalcon\Test\Models\AlbumORama\Artists');
                }
            }
        );
    }
}
