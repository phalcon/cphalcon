<?php

namespace Some;

use Phalcon\Db\Column;
use Phalcon\Mvc\Model\MetaData;

class Products extends \Phalcon\Mvc\Model
{

	public function getSource(){
		return 'le_products';
	}

	public function metaData()
	{
		return array(
			MetaData::MODELS_ATTRIBUTES => array(
				'id', 'name', 'type', 'price'
			),
			MetaData::MODELS_PRIMARY_KEY => array(
				'id'
			),
			MetaData::MODELS_NON_PRIMARY_KEY => array(
				'name', 'type', 'price'
			),
			MetaData::MODELS_NOT_NULL => array(
				'id', 'name', 'type', 'price'
			),
			MetaData::MODELS_DATA_TYPES => array(
				'id' => Column::TYPE_INTEGER,
				'name' => Column::TYPE_VARCHAR,
				'type' => Column::TYPE_VARCHAR,
				'price' => Column::TYPE_INTEGER
			),
			MetaData::MODELS_DATA_TYPES_NUMERIC => array(
				'id' => true,
				'price' => true,
			),
			MetaData::MODELS_IDENTITY_COLUMN => 'id',
			MetaData::MODELS_DATA_TYPES_BIND => array(
				'id' => Column::BIND_PARAM_INT,
				'name' => Column::BIND_PARAM_STR,
				'type' => Column::BIND_PARAM_STR,
				'price' => Column::BIND_PARAM_INT,
			),
			MetaData::MODELS_AUTOMATIC_DEFAULT_INSERT => array(),
			MetaData::MODELS_AUTOMATIC_DEFAULT_UPDATE => array()
		);
	}

}