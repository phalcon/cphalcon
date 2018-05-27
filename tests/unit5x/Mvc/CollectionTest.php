<?php

namespace Phalcon\Test\Unit5x\Mvc;

use Helper\CollectionTrait;
use Phalcon\Mvc\Collection;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Collections\Songs;
use Phalcon\Test\Collections\Store\Songs as StoreSongs;

/**
 * Phalcon\Test\Unit5x\Mvc\CollectionTest
 * Tests the Phalcon\Mvc\Collection component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit5x\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CollectionTest extends UnitTest
{
    use CollectionTrait;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $this->setupMongo($this->tester);
    }

    /**
     * Tests triggering exception on update non existent document
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testShouldCatchExceptionOnUpdateNonExistentDocument()
    {
        $this->specify(
            "Test does not catch Collection Exception on update non existent document",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Legs and Tarpaulin';
                $song->update();
            },
            [
                'throws' => [
                    'Phalcon\Mvc\Collection\Exception',
                    "The document cannot be updated because it doesn't exist"
                ]
            ]
        );
    }

    /**
     * Tests Collection::save
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldGetTrueWhenSaveDocument()
    {
        $this->specify(
            "Collection::save does not return expected result",
            function () {
                $this->clearCollection();
                expect($this->createDocument(['artist' => 'Radiohead', 'name' => 'Lotus Flower']))->true();
            }
        );
    }

    /**
     * Tests Collection::find
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testShouldGetArrayOfCollectionsByUsingFind()
    {
        $this->specify(
            "Collection::find does not return expected result",
            function () {
                $songs = Songs::find();
                expect(is_array($songs))->true();

                $this->clearCollection();

                $this->createDocument([
                    'artist' => 'Radiohead',
                    'name'   => 'Lotus Flower',
                ]);

                $songs = Songs::find();

                expect(is_array($songs))->true();
                expect($songs)->count(1);
                expect($songs[0]->_id)->isInstanceOf('MongoId');
                expect($songs[0]->artist)->equals('Radiohead');
                expect($songs[0]->name)->equals('Lotus Flower');

                $this->createDocument([
                    'artist' => 'Massive Attack',
                    'name'   => 'Teardrop',
                ]);

                $songs = Songs::find();

                expect(is_array($songs))->true();
                expect($songs)->count(2);
                expect($songs[1]->_id)->isInstanceOf('MongoId');
                expect($songs[1]->artist)->equals('Massive Attack');
                expect($songs[1]->name)->equals('Teardrop');
                expect((string) $songs[0]->_id)->notEquals((string) $songs[1]->_id);

                $this->createDocument([
                    'artist' => 'Massive Attack',
                    'name'   => 'Paradise Circus',
                ]);

                $songs = Songs::find();

                expect(is_array($songs))->true();
                expect($songs)->count(3);
                expect($songs[2]->_id)->isInstanceOf('MongoId');
                expect($songs[2]->artist)->equals('Massive Attack');
                expect($songs[2]->name)->equals('Paradise Circus');
                expect((string) $songs[0]->_id)->notEquals((string) $songs[1]->_id);
                expect((string) $songs[1]->_id)->notEquals((string) $songs[2]->_id);
                expect((string) $songs[2]->_id)->notEquals((string) $songs[0]->_id);

                $songs = Songs::find([['artist' => 'Massive Attack']]);

                expect(is_array($songs))->true();
                expect($songs)->count(2);
                expect($songs[0]->name)->equals('Teardrop');
                expect($songs[1]->name)->equals('Paradise Circus');

                $songs = Songs::find(['conditions' => ['artist' => 'Massive Attack']]);

                expect(is_array($songs))->true();
                expect($songs)->count(2);
                expect($songs[0]->name)->equals('Teardrop');
                expect($songs[1]->name)->equals('Paradise Circus');

                $songs = Songs::find([
                    'conditions' => ['artist' => 'Massive Attack'],
                    'sort'       => ['name' => 1],
                ]);

                expect($songs[0]->name)->equals('Paradise Circus');
                expect($songs[1]->name)->equals('Teardrop');


                $songs = Songs::find([
                    'conditions' => ['artist' => 'Massive Attack'],
                    'sort'       => ['name' => 1],
                    'limit'      => 1
                ]);

                expect(is_array($songs))->true();
                expect($songs)->count(1);
                expect($songs[0]->name)->equals('Paradise Circus');

                $songs = Songs::find([
                    'conditions' => ['artist' => 'Massive Attack'],
                    'limit'      => 1
                ]);

                expect(is_array($songs))->true();
                expect($songs)->count(1);
                expect($songs[0]->name)->equals('Teardrop');
            }
        );
    }

    /**
     * Tests Collection::findFirst
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldGetCollectionByUsingFindFirst()
    {
        $this->specify(
            "Collection::findFirst does not return expected result",
            function () {
                $song = Songs::findFirst();

                expect($song->artist)->equals('Radiohead');
                expect($song->name)->equals('Lotus Flower');

                $song = Songs::findFirst([['artist' => 'Massive Attack']]);

                expect($song->artist)->equals('Massive Attack');
                expect($song->name)->equals('Teardrop');

                $song = Songs::findFirst(['conditions' => ['name' => 'Paradise Circus']]);

                expect($song->artist)->equals('Massive Attack');
                expect($song->name)->equals('Paradise Circus');

                expect(Songs::findFirst([['artist' => 'Lana']]))->false();
                expect(Songs::findFirst(['conditions' => ['artist' => 'Lana']]))->false();
            }
        );
    }

    /**
     * Tests Collection::count
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldCountDocumentsInCollection()
    {
        $this->specify(
            "Collection::count does not return expected result",
            function () {
                expect(Songs::count())->equals(3);
                expect(Songs::count([['artist' => 'Massive Attack']]))->equals(2);
            }
        );
    }

    /**
     * Tests Collection::create
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldCreateDocument()
    {
        $this->specify(
            "Collection::create does not work correctly",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Greensward Grey';

                expect($song->create())->true();
                expect(Songs::count())->equals(4);
            }
        );
    }

    /**
     * Tests Collection::createIfNotExist
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-13
     */
    public function testShouldCreateIfNotExistDocument()
    {
        $this->specify(
            "Collection::createIfNotExist does not work correctly",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Catacomb Kittens';


                expect($song->createIfNotExist(['name', 'artist']))->true();

                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Catacomb Kittens';

                expect($song->createIfNotExist(['name', 'artist']))->false();

                expect(Songs::count())->equals(5);
                expect(Songs::count([['artist' => 'Cinema Strange']]))->equals(2);
            }
        );
    }

    public function testShouldUpdateDocument()
    {
        $this->specify(
            "Collection::update does not work correctly",
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Hebenon Vial';
                $song->create();

                $song->name = "Lindsey's Trachea";
                expect($song->update())->true();
                expect(Songs::count())->equals(6);
                expect(Songs::count([['name' => 'Hebenon Vial']]))->equals(0);
            }
        );
    }

    /**
     * Tests Collection::findById
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-07-24
     * @issue  https://github.com/phalcon/cphalcon/issues/12010
     */
    public function testShouldUseCorrectMongoId()
    {
        $this->specify(
            'The Collection::findById does not return expected result',
            function () {
                $song = new Songs();
                $song->artist = 'Jo Blankenburg';
                $song->name = 'Valkyrie';
                $song->create();

                $mongoIdObject = $song->_id;

                expect(Songs::findById($mongoIdObject->__toString()))->isInstanceOf('\Phalcon\Mvc\CollectionInterface');
                expect(Songs::findById($mongoIdObject))->isInstanceOf('\Phalcon\Mvc\CollectionInterface');

                expect(Songs::findById('qwerty-1234'))->null();
                expect(Songs::findById('s'))->null();
                expect(Songs::findById(str_repeat('0', 25)))->null();
                expect(Songs::findById(''))->null();
                expect(Songs::findById(null))->null();
                expect(Songs::findById(false))->null();
            }
        );
    }

    protected function createDocument(array $fields)
    {
        $song = new Songs();

        foreach ($fields as $name => $value) {
            $song->{$name} = $value;
        }

        return $song->save();
    }

    protected function clearCollection()
    {
        foreach (Songs::find() as $song) {
            $this->assertTrue($song->delete());
        }
    }

    public function testCollectionsSerialize()
    {
        $this->specify(
            "Collections don't serialize/unserialize as expected",
            function () {
                $songs = StoreSongs::find();
                expect(is_array($songs))->true();

                foreach ($songs as $song) {
                    expect($song->delete())->true();
                }

                $trace = [];

                $song = new Songs();
                $song->artist = "Radiohead";
                $song->name = "Lotus Flower";
                expect($song->save())->true();

                $serialized = serialize($song);
                $song = unserialize($serialized);

                expect($song->artist)->equals("Radiohead");
                expect($song->name)->equals("Lotus Flower");
                expect($song->save())->true();

                $song = Songs::findFirst();

                $serialized = serialize($song);
                $song = unserialize($serialized);

                expect($song->artist)->equals("Radiohead");
                expect($song->name)->equals("Lotus Flower");
                expect($song->save())->true();

                $song = new Songs();
                $song->artist = "Massive Attack";
                $song->name = "Paradise Circus";
                expect($song->save())->true();

                $songs = Songs::find();
                expect($songs)->count(2);

                $serialized = serialize($songs);
                $songs = unserialize($serialized);

                expect($songs)->count(2);
            }
        );
    }

    public function testCollectionsEvents()
    {
        $this->specify(
            "Collection events don't work as expected",
            function () {
                $songs = StoreSongs::find();
                expect(is_array($songs))->true();

                foreach ($songs as $song) {
                    expect($song->delete())->true();
                }

                $trace = array();

                $song = new StoreSongs();
                $song->trace = &$trace;
                $song->artist = 'Radiohead';
                $song->name = 'Lotus Flower';
                expect($song->save())->true();

                expect($trace)->equals(
                    array(
                        StoreSongs::class . '::beforeValidation' => 1,
                        StoreSongs::class . '::beforeValidationOnCreate' => 1,
                        StoreSongs::class . '::afterValidationOnCreate' => 1,
                        StoreSongs::class . '::afterValidation' => 1,
                        StoreSongs::class . '::beforeSave' => 1,
                        StoreSongs::class . '::beforeCreate' => 1,
                        StoreSongs::class . '::afterCreate' => 1,
                        StoreSongs::class . '::afterSave' => 1,
                    )
                );

                $this->assertTrue($song->save());

                expect($trace)->equals(
                    array(
                        StoreSongs::class . '::beforeValidation' => 2,
                        StoreSongs::class . '::beforeValidationOnCreate' => 1,
                        StoreSongs::class . '::afterValidationOnCreate' => 1,
                        StoreSongs::class . '::afterValidation' => 2,
                        StoreSongs::class . '::beforeSave' => 2,
                        StoreSongs::class . '::beforeCreate' => 1,
                        StoreSongs::class . '::afterCreate' => 1,
                        StoreSongs::class . '::afterSave' => 2,
                        StoreSongs::class . '::afterValidationOnUpdate' => 1,
                        StoreSongs::class . '::beforeUpdate' => 1,
                        StoreSongs::class . '::afterUpdate' => 1,
                    )
                );
            }
        );
    }

    /**
     * Tests Collection dirty state
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-10
     */
    public function testDirtyState()
    {
        $this->specify(
            'Dirty state is not set properly',
            function () {
                $song = new Songs();
                $song->artist = 'Cinema Strange';
                $song->name = 'Hebenon Vial';
                expect($song->getDirtyState())->equals(Collection::DIRTY_STATE_TRANSIENT);
                $song->create();
                expect($song->getDirtyState())->equals(Collection::DIRTY_STATE_PERSISTENT);
                $id = $song->getId();
                $song = Songs::findById($id);
                expect($song->getDirtyState())->equals(Collection::DIRTY_STATE_PERSISTENT);
                $song->delete();
                expect($song->getDirtyState())->equals(Collection::DIRTY_STATE_DETACHED);
            }
        );
    }
}
