<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData;

use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Metadata\Files;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\FilesCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Files component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Phalcon Team <team@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Metadata
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FilesCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        $I->haveServiceInDi('modelsMetadata', function () {
            return new Files([
                'metaDataDir' => cacheFolder(),
            ]);
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';
    }

    public function files(UnitTester $I)
    {
        $I->wantTo('fetch metadata from file cache');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->amInPath(cacheFolder());

        $I->seeFileFound('meta-phalcon_test_models_robots-robots.php');

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            require cacheFolder('meta-phalcon_test_models_robots-robots.php')
        );

        $I->seeFileFound('map-phalcon_test_models_robots.php');

        $I->assertEquals(
            $this->data['map-robots'],
            require cacheFolder('map-phalcon_test_models_robots.php')
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());

        $I->safeDeleteFile('meta-phalcon_test_models_robots-robots.php');
        $I->safeDeleteFile('map-phalcon_test_models_robots.php');
    }
}
