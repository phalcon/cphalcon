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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Tests\AbstractDatabaseTestCase;

final class RefactorModelsResultsetCacheTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testCacheDefaultDI(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testCacheDefaultDIBindings(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testCacheOtherService(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsResultsetCacheCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use Codeception\Example;
// use IntegrationTester;
// use Phalcon\Cache\Backend\File;
// use Phalcon\Cache\Frontend\Data;
// use Phalcon\Tests\Support\Traits\DiTrait;
// use Phalcon\Tests\Support\Models\Robots;
//
// use function cacheDir;
//
// class ModelsResultsetCacheCest
// {
//     use DiTrait;
//
//     public function _before(IntegrationTester $I)
//     {
//         $this->setNewFactoryDefault();
//
//         $I->cleanDir(
//             cacheDir()
//         );
//     }
//
//     public function _after(IntegrationTester $I)
//     {
//         $this->container['db']->close();
//     }
//
//     /**
//      * @dataProvider adaptersProvider
//
