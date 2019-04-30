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

namespace Phalcon\Test\Fixtures\Traits;

use UnitTester;
use function dataDir;

/**
 * @package Phalcon\Test\Fixtures\Traits
 */
trait TranslateTrait
{
    /**
     * Executed before each test
     */
    public function _before(UnitTester $I, $scenario)
    {
        $I->checkExtensionIsLoaded('gettext');

        if (!setlocale(LC_ALL, 'en_US.utf8')) {
            $scenario->skip("Locale en_US.utf8 not enabled");
        }
    }

    protected function getArrayConfig(): array
    {
        return [
            'en' => [
                'hi'        => 'Hello',
                'bye'       => 'Good Bye',
                'hello-key' => 'Hello %name%',
                'song-key'  => 'This song is %song% (%artist%)',
            ],
            'es' => [
                'hi'        => 'Hola',
                'bye'       => 'Adiós',
                'hello-key' => 'Hola %name%',
                'song-key'  => 'La canción es %song% (%artist%)',
            ],
            'fr' => [
                'hi'        => 'Bonjour',
                'bye'       => 'Au revoir',
                'hello-key' => 'Bonjour %name%',
                'song-key'  => 'La chanson est %song% (%artist%)',
            ],
            'ru' => [
                'Hello!'                         => 'Привет!',
                'Hello %fname% %mname% %lname%!' => 'Привет, %fname% %mname% %lname%!',
            ],
        ];
    }

    protected function getCsvConfig(): array
    {
        return [
            'ru' => [
                'content' => dataDir('assets/translation/csv/ru_RU.csv'),
            ],
        ];
    }

    protected function getGettextConfig(): array
    {
        return [
            'locale'        => 'en_US.utf8',
            'defaultDomain' => 'messages',
            'directory'     => dataDir('assets/translation/gettext'),
            'category'      => LC_MESSAGES,
        ];
    }
}
