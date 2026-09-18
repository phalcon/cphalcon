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

namespace Phalcon\Tests\Database\Mvc;

use PDO;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\AlbumsMigration;
use Phalcon\Tests\Support\Migrations\ArtistsMigration;
use Phalcon\Tests\Support\Models\AlbumORama\Albums;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class ModelTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testExecuteCamelCaseRelation(): void
    {
        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new ArtistsMigration($connection))->insert(1, 'Test Artist');
        (new AlbumsMigration($connection))->insert(1, 1, 'Test Album');

        $album = Albums::findFirst();

        // Mutating through the lowercase alias must be visible through
        // the CamelCase form - relation accessors are case-insensitive
        // and resolve to the same lazy-loaded related model.
        $album->artist->name = 'NotArtist';

        $this->assertSame($album->Artist->name, $album->artist->name);
    }
}
