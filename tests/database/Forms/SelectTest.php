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

namespace Phalcon\Tests\Database\Forms;

use Phalcon\Forms\Element\Select;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tag\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\SelectMigration;
use Phalcon\Tests\Support\Models\Select as SelectModel;
use Phalcon\Tests\Support\Traits\DiTrait;

final class SelectTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        $migration  = new SelectMigration($connection);
        $migration->insert('Alpha', 'First option');
        $migration->insert('Beta', 'Second option');
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * Tests Phalcon\Forms\Element\Select :: render() with ResultsetInterface options
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-09
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testSelectRenderWithResultset(): void
    {
        $resultset = SelectModel::find();

        $element = new Select('region', $resultset);
        $element->setTagFactory(new TagFactory(new Escaper()));

        $html = $element->render(['using' => ['sel_id', 'sel_name']]);

        $this->assertStringContainsString('<select', $html);
        $this->assertStringContainsString('Alpha', $html);
        $this->assertStringContainsString('Beta', $html);
    }

    /**
     * Tests Phalcon\Forms\Element\Select :: render() with ResultsetInterface
     * and no 'using' parameter throws an exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-09
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testSelectRenderWithResultsetThrowsWithoutUsing(): void
    {
        $resultset = SelectModel::find();

        $element = new Select('region', $resultset);
        $element->setTagFactory(new TagFactory(new Escaper()));

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("The 'using' parameter is required");

        $element->render();
    }
}
