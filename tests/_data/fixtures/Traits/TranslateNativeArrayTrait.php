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

namespace Phalcon\Tests\Fixtures\Traits;

trait TranslateNativeArrayTrait
{
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
}
