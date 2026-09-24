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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Stream;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaData\Stream;
use Phalcon\Talon\Talon;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

use function file_put_contents;
use function strtolower;

#[Group('phql')]
final class ReadMetaDataTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        (new InvoicesMigration(self::getPdoConnection()))->clear();
    }

    public function tearDown(): void
    {
        $this->safeDeleteFile($this->getFile('meta'));
        $this->safeDeleteFile($this->getFile('map'));

        $this->tearDownDatabase();
    }

    /**
     * @return array<array-key, array<array-key, string>>
     */
    public static function getExamples(): array
    {
        return [
            'empty file'     => [''],
            'truncated file' => ["<?php return array ( 0 => array ( 0 => 'inv"],
            'scalar value'   => ['<?php return 1; '],
        ];
    }

    /**
     * A cache file that is empty, partially written or does not return an
     * array is a cache miss. The meta-data is read again from the database
     * and the cache file is written again.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17608
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-24
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelMetadataStreamReadMetaDataInvalidFile(
        string $contents
    ): void {
        file_put_contents($this->getFile('meta'), $contents);
        file_put_contents($this->getFile('map'), $contents);

        $metadata = new Stream(
            [
                'metaDataDir' => Talon::settings()->outputPath('tests/cache/'),
            ]
        );
        $metadata->setDi($this->container);

        $this->container->setShared('modelsMetadata', $metadata);

        $key    = strtolower(Invoices::class);
        $model  = new Invoices();
        $result = $metadata->readMetaData($model);

        $this->assertIsArray($result);
        $this->assertEquals(
            ['inv_id'],
            $result[MetaData::MODELS_PRIMARY_KEY]
        );
        $this->assertIsArray($metadata->readColumnMap($model));

        $this->assertIsArray($metadata->read('meta-' . $key));
        $this->assertIsArray($metadata->read('map-' . $key));
    }

    private function getFile(string $prefix): string
    {
        return Talon::settings()->outputPath(
            'tests/cache/' . $prefix . '-phalcon_tests_support_models_invoices.php'
        );
    }
}
