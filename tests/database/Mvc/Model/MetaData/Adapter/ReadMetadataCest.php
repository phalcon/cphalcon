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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Adapter;

use Codeception\Example;
use DatabaseTester;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Migrations\AlbumMigration;
use Phalcon\Tests\Fixtures\Migrations\AlbumPhotoMigration;
use Phalcon\Tests\Fixtures\Migrations\PhotoMigration;
use Phalcon\Tests\Fixtures\models\Album;
use Phalcon\Tests\Fixtures\models\AlbumPhoto;
use Phalcon\Tests\Fixtures\models\Photo;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function array_keys;

class ReadMetadataCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getAttributes() - Redis
     *
     * @dataProvider getExamples
     *
     * @param DatabaseTester $I
     * @param Example $example
     *
     * @return void
     * @throws Exception
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-07-01
     *
     * @group  mysql
     *
     */
    public function mvcModelMetadataGetAttributesRedis(
        DatabaseTester $I,
        Example $example
    ) {
        $keys = $example['keys'];
        $service = $example['service'];

        $I->wantToTest('Mvc\Model\MetaData - readMetadata() - ' . $service);

        $connection = $I->getConnection();
        $adapter = $this->newService($service);

        /**
         * Cleanup Redis
         */
        $adapter->reset();

        $this->container->setShared('modelsMetadata', $adapter);

        (new PhotoMigration($connection));
        (new AlbumMigration($connection));
        (new AlbumPhotoMigration($connection));

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model = new Album();
        $expected = [
            'id',
            'name',
            'album_id',
            'photo_id',
        ];
        $actual = $metadata->getAttributes($model);
        $I->assertEquals($expected, $actual);

        $model = new AlbumPhoto();
        $expected = [
            'id',
            'photo_id',
            'album_id',
            'position',
        ];
        $actual = $metadata->getAttributes($model);
        $I->assertEquals($expected, $actual);

        $model = new Photo();
        $expected = [
            'id',
            'date_uploaded',
            'original_filename',
            'path',
            'width',
            'height',
            'thumb_path',
            'thumb_width',
            'thumb_height',
            'display_path',
            'display_width',
            'display_height',
            'mime_type',
            'filesize',
            'phash',
            'battles',
            'wins',
        ];
        $actual = $metadata->getAttributes($model);
        $I->assertEquals($expected, $actual);

        $service = $adapter->getAdapter();

        /**
         * Check if keys exist
         */
        $keyKeys = array_keys($keys);
        foreach ($keyKeys as $key) {
            $actual = $service->has($key);
            $I->assertTrue($actual);
        }

        /**
         * Check contents of the keys
         */
        foreach ($keys as $key => $expected) {
            $actual = $service->get($key);
            $I->assertSame($expected, $actual);
        }
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'service' => 'metadataRedis',
                'keys' => [
                    'meta-phalcon\tests\fixtures\models\albumphoto-album_photo' => [
                        0 => [
                            'id',
                            'photo_id',
                            'album_id',
                            'position',
                        ],
                        1 => [
                            'id'
                        ],
                        2 => [
                            'photo_id',
                            'album_id',
                            'position',
                        ],
                        3 => [
                            'id',
                            'position',
                        ],
                        4 => [
                            'id' => 0,
                            'photo_id' => 0,
                            'album_id' => 0,
                            'position' => 0,
                        ],
                        5 => [
                            'id' => true,
                            'photo_id' => true,
                            'album_id' => true,
                            'position' => true,
                        ],
                        8 => 'id',
                        9 => [
                            'id' => 1,
                            'photo_id' => 1,
                            'album_id' => 1,
                            'position' => 1,
                        ],
                        10 => [],
                        11 => [],
                        12 => [
                            'photo_id' => null,
                            'album_id' => null,
                            'position' => '999999999',
                        ],
                        13 => [],
                    ],
                    'map-phalcon\tests\fixtures\models\album' => [
                        0 => null,
                        1 => null,
                    ],
                    'map-phalcon\tests\fixtures\models\albumphoto' => [
                        0 => null,
                        1 => null,
                    ],
                    'meta-phalcon\tests\fixtures\models\photo-photo' => [
                        0 => [
                            'id',
                            'date_uploaded',
                            'original_filename',
                            'path',
                            'width',
                            'height',
                            'thumb_path',
                            'thumb_width',
                            'thumb_height',
                            'display_path',
                            'display_width',
                            'display_height',
                            'mime_type',
                            'filesize',
                            'phash',
                            'battles',
                            'wins',
                        ],
                        1 => [
                            'id'
                        ],
                        2 => [
                            'date_uploaded',
                            'original_filename',
                            'path',
                            'width',
                            'height',
                            'thumb_path',
                            'thumb_width',
                            'thumb_height',
                            'display_path',
                            'display_width',
                            'display_height',
                            'mime_type',
                            'filesize',
                            'phash',
                            'battles',
                            'wins',
                        ],
                        3 => [
                            'id',
                            'date_uploaded',
                            'original_filename',
                            'path',
                            'width',
                            'height',
                            'thumb_path',
                            'thumb_width',
                            'thumb_height',
                            'display_path',
                            'display_width',
                            'display_height',
                            'mime_type',
                            'phash',
                            'battles',
                            'wins',
                        ],
                        4 => [
                            'id' => 0,
                            'date_uploaded' => 4,
                            'original_filename' => 6,
                            'path' => 6,
                            'width' => 22,
                            'height' => 22,
                            'thumb_path' => 6,
                            'thumb_width' => 22,
                            'thumb_height' => 22,
                            'display_path' => 6,
                            'display_width' => 22,
                            'display_height' => 22,
                            'mime_type' => 2,
                            'filesize' => 0,
                            'phash' => 14,
                            'battles' => 0,
                            'wins' => 0,
                        ],
                        5 => [
                            'id' => true,
                            'width' => true,
                            'height' => true,
                            'thumb_width' => true,
                            'thumb_height' => true,
                            'display_width' => true,
                            'display_height' => true,
                            'filesize' => true,
                            'phash' => true,
                            'battles' => true,
                            'wins' => true,
                        ],
                        8 => 'id',
                        9 => [
                            'id' => 1,
                            'date_uploaded' => 2,
                            'original_filename' => 2,
                            'path' => 2,
                            'width' => 1,
                            'height' => 1,
                            'thumb_path' => 2,
                            'thumb_width' => 1,
                            'thumb_height' => 1,
                            'display_path' => 2,
                            'display_width' => 1,
                            'display_height' => 1,
                            'mime_type' => 2,
                            'filesize' => 1,
                            'phash' => 2,
                            'battles' => 1,
                            'wins' => 1,
                        ],
                        10 => [],
                        11 => [],
                        12 => [
                            'date_uploaded' => 'CURRENT_TIMESTAMP',
                            'filesize' => null,
                            'battles' => '0',
                            'wins' => '0',
                        ],
                        13 => [],
                    ],
                    'map-phalcon\tests\fixtures\models\photo' => [
                        0 => null,
                        1 => null,
                    ],
                    'meta-phalcon\tests\fixtures\models\album-album' => [
                        0 => [
                            'id',
                            'name',
                            'album_id',
                            'photo_id',
                        ],
                        1 => [
                            'id',
                        ],
                        2 => [
                            'name',
                            'album_id',
                            'photo_id',
                        ],
                        3 => [
                            'id',
                            'name',
                        ],
                        4 => [
                            'id' => 0,
                            'name' => 2,
                            'album_id' => 0,
                            'photo_id' => 0,
                        ],
                        5 => [
                            'id' => true,
                            'album_id' => true,
                            'photo_id' => true,
                        ],
                        8 => 'id',
                        9 => [
                            'id' => 1,
                            'name' => 2,
                            'album_id' => 1,
                            'photo_id' => 1,
                        ],
                        10 => [],
                        11 => [],
                        12 => [
                            'album_id' => null,
                            'photo_id' => null,
                        ],
                        13 => [],
                    ],
                ],
            ],
            [
                'service' => 'metadataLibmemcached',
                'keys' => [
                    'meta-phalcon\tests\fixtures\models\albumphoto-album_photo' => [
                        0 => [
                            'id',
                            'photo_id',
                            'album_id',
                            'position',
                        ],
                        1 => [
                            'id'
                        ],
                        2 => [
                            'photo_id',
                            'album_id',
                            'position',
                        ],
                        3 => [
                            'id',
                            'position',
                        ],
                        4 => [
                            'id' => 0,
                            'photo_id' => 0,
                            'album_id' => 0,
                            'position' => 0,
                        ],
                        5 => [
                            'id' => true,
                            'photo_id' => true,
                            'album_id' => true,
                            'position' => true,
                        ],
                        8 => 'id',
                        9 => [
                            'id' => 1,
                            'photo_id' => 1,
                            'album_id' => 1,
                            'position' => 1,
                        ],
                        10 => [],
                        11 => [],
                        12 => [
                            'photo_id' => null,
                            'album_id' => null,
                            'position' => '999999999',
                        ],
                        13 => [],
                    ],
                    'map-phalcon\tests\fixtures\models\album' => [
                        0 => null,
                        1 => null,
                    ],
                    'map-phalcon\tests\fixtures\models\albumphoto' => [
                        0 => null,
                        1 => null,
                    ],
                    'meta-phalcon\tests\fixtures\models\photo-photo' => [
                        0 => [
                            'id',
                            'date_uploaded',
                            'original_filename',
                            'path',
                            'width',
                            'height',
                            'thumb_path',
                            'thumb_width',
                            'thumb_height',
                            'display_path',
                            'display_width',
                            'display_height',
                            'mime_type',
                            'filesize',
                            'phash',
                            'battles',
                            'wins',
                        ],
                        1 => [
                            'id'
                        ],
                        2 => [
                            'date_uploaded',
                            'original_filename',
                            'path',
                            'width',
                            'height',
                            'thumb_path',
                            'thumb_width',
                            'thumb_height',
                            'display_path',
                            'display_width',
                            'display_height',
                            'mime_type',
                            'filesize',
                            'phash',
                            'battles',
                            'wins',
                        ],
                        3 => [
                            'id',
                            'date_uploaded',
                            'original_filename',
                            'path',
                            'width',
                            'height',
                            'thumb_path',
                            'thumb_width',
                            'thumb_height',
                            'display_path',
                            'display_width',
                            'display_height',
                            'mime_type',
                            'phash',
                            'battles',
                            'wins',
                        ],
                        4 => [
                            'id' => 0,
                            'date_uploaded' => 4,
                            'original_filename' => 6,
                            'path' => 6,
                            'width' => 22,
                            'height' => 22,
                            'thumb_path' => 6,
                            'thumb_width' => 22,
                            'thumb_height' => 22,
                            'display_path' => 6,
                            'display_width' => 22,
                            'display_height' => 22,
                            'mime_type' => 2,
                            'filesize' => 0,
                            'phash' => 14,
                            'battles' => 0,
                            'wins' => 0,
                        ],
                        5 => [
                            'id' => true,
                            'width' => true,
                            'height' => true,
                            'thumb_width' => true,
                            'thumb_height' => true,
                            'display_width' => true,
                            'display_height' => true,
                            'filesize' => true,
                            'phash' => true,
                            'battles' => true,
                            'wins' => true,
                        ],
                        8 => 'id',
                        9 => [
                            'id' => 1,
                            'date_uploaded' => 2,
                            'original_filename' => 2,
                            'path' => 2,
                            'width' => 1,
                            'height' => 1,
                            'thumb_path' => 2,
                            'thumb_width' => 1,
                            'thumb_height' => 1,
                            'display_path' => 2,
                            'display_width' => 1,
                            'display_height' => 1,
                            'mime_type' => 2,
                            'filesize' => 1,
                            'phash' => 2,
                            'battles' => 1,
                            'wins' => 1,
                        ],
                        10 => [],
                        11 => [],
                        12 => [
                            'date_uploaded' => 'CURRENT_TIMESTAMP',
                            'filesize' => null,
                            'battles' => '0',
                            'wins' => '0',
                        ],
                        13 => [],
                    ],
                    'map-phalcon\tests\fixtures\models\photo' => [
                        0 => null,
                        1 => null,
                    ],
                    'meta-phalcon\tests\fixtures\models\album-album' => [
                        0 => [
                            'id',
                            'name',
                            'album_id',
                            'photo_id',
                        ],
                        1 => [
                            'id',
                        ],
                        2 => [
                            'name',
                            'album_id',
                            'photo_id',
                        ],
                        3 => [
                            'id',
                            'name',
                        ],
                        4 => [
                            'id' => 0,
                            'name' => 2,
                            'album_id' => 0,
                            'photo_id' => 0,
                        ],
                        5 => [
                            'id' => true,
                            'album_id' => true,
                            'photo_id' => true,
                        ],
                        8 => 'id',
                        9 => [
                            'id' => 1,
                            'name' => 2,
                            'album_id' => 1,
                            'photo_id' => 1,
                        ],
                        10 => [],
                        11 => [],
                        12 => [
                            'album_id' => null,
                            'photo_id' => null,
                        ],
                        13 => [],
                    ],
                ],
            ],
        ];
    }
}
