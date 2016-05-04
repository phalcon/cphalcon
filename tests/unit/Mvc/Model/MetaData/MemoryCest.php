<?php

namespace Phalcon\Test\Unit\Mvc\Model\Metadata;

use Phalcon\Di;
use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Proxy\Mvc\Model\Metadata\Memory;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\MemoryCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Memory component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Metadata
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MemoryCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        $I->haveServiceInDi('modelsMetadata', function() {
            return new Memory;
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';
    }

    public function redis(UnitTester $I)
    {
        $I->wantTo('fetch metadata from memory');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
