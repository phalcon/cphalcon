<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Dynamic;

use Phalcon\Mvc\Model as PhalconModel;
use Phalcon\Mvc\Model\Behavior\SoftDelete;

/**
 * @property string $borgerId
 * @property int    $slagBorgerId
 * @property string $navnes
 * @property string $telefon
 * @property string $adresse
 * @property string $elektroniskPost
 * @property string $fodtDato
 * @property int    $fodebyId
 * @property int    $skabtPa
 * @property float  $kredit
 * @property string $status
 *
 * @method static Personers findFirst($parameters = null)
 */
class Personers extends PhalconModel
{
    public function initialize()
    {
        $this->setSource('personas');

        $this->useDynamicUpdate(true);

        $this->addBehavior(
            new SoftDelete(
                [
                    'field' => 'status',
                    'value' => 'X',
                ]
            )
        );
    }

    public function columnMap()
    {
        return [
            'cedula'            => 'borgerId',
            'tipo_documento_id' => 'slagBorgerId',
            'nombres'           => 'navnes',
            'telefono'          => 'telefon',
            'direccion'         => 'adresse',
            'email'             => 'elektroniskPost',
            'fecha_nacimiento'  => 'fodtDato',
            'ciudad_id'         => 'fodebyId',
            'creado_at'         => 'skabtPa',
            'cupo'              => 'kredit',
            'estado'            => 'status',
        ];
    }
}
